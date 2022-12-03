#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef double db;
const int N=2002;
const db inf=1e11,eps=1e-9;
int n,sx,sy,ex,ey,sb,eb;db V,ans;
int X1[N],X2[N],Y1[N],Y2[N],L[N],R[N];db f[N][2];
db getk(db xx1,db yy1,db xx2,db yy2) {return (yy2-yy1)/(xx2-xx1);}
db dist(db xx1,db yy1,db xx2,db yy2)
\t{return sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2));}
void work() {
\tif(sx==ex) {printf("%.8lf
",dist(sx,sy,ex,ey)/V);return;}//\u8d77\u70b9\u7ec8\u70b9\u6a2a\u5750\u6807\u76f8\u540c
\tfor(RI i=1;i<=n;++i) f[i][0]=f[i][1]=inf;
\tfor(RI i=1;i<n;++i) L[i]=max(Y1[i],Y1[i+1]),R[i]=min(Y2[i],Y2[i+1]);
\tdb kl=-inf,kr=inf;ans=inf;
\tfor(RI i=sb;i<eb;++i) {
\t\tif(i==sb&&sx==X2[i]) {//\u8d77\u70b9\u548c\u7b2c\u4e00\u4e2a\u5173\u952e\u70b9\u6a2a\u5750\u6807\u76f8\u540c
\t\t\tf[i][0]=dist(sx,sy,X2[i],L[i]);
\t\t\tf[i][1]=dist(sx,sy,X2[i],R[i]);
\t\t\tif(sy<Y1[i]||sy>Y2[i]) {kl=inf,kr=-inf;break;}
\t\t}
\t\tdb ll=getk(sx,sy,X2[i],L[i]),rr=getk(sx,sy,X2[i],R[i]);
\t\tif(kl<ll+eps&&kr+eps>ll) f[i][0]=dist(sx,sy,X2[i],L[i]);
\t\tif(kl<rr+eps&&kr+eps>rr) f[i][1]=dist(sx,sy,X2[i],R[i]);
\t\tkl=max(kl,ll),kr=min(kr,rr);
\t}
\tdb kk=getk(sx,sy,ex,ey);
\tif(kl<kk+eps&&kr+eps>kk) ans=dist(sx,sy,ex,ey);
\tfor(RI i=sb;i<eb;++i) {
\t\tdb kl1=-inf,kr1=inf,kl2=-inf,kr2=inf;
\t\tfor(RI j=i+1;j<eb;++j) {
\t\t\tdb ll=getk(X2[i],L[i],X2[j],L[j]),rr=getk(X2[i],L[i],X2[j],R[j]);
\t\t\tif(kl1<ll+eps&&kr1+eps>ll)
\t\t\t\tf[j][0]=min(f[i][0]+dist(X2[i],L[i],X2[j],L[j]),f[j][0]);
\t\t\tif(kl1<rr+eps&&kr1+eps>rr)
\t\t\t\tf[j][1]=min(f[i][0]+dist(X2[i],L[i],X2[j],R[j]),f[j][1]);
\t\t\tkl1=max(kl1,ll),kr1=min(kr1,rr);
\t\t\tll=getk(X2[i],R[i],X2[j],L[j]),rr=getk(X2[i],R[i],X2[j],R[j]);
\t\t\tif(kl2<ll+eps&&kr2+eps>ll)
\t\t\t\tf[j][0]=min(f[i][1]+dist(X2[i],R[i],X2[j],L[j]),f[j][0]);
\t\t\tif(kl2<rr+eps&&kr2+eps>rr)
\t\t\t\tf[j][1]=min(f[i][1]+dist(X2[i],R[i],X2[j],R[j]),f[j][1]);
\t\t\tkl2=max(kl2,ll),kr2=min(kr2,rr);
\t\t}
\t\tif(i==eb-1&&ex==X1[eb]) {//\u7ec8\u70b9\u548c\u6700\u540e\u4e00\u4e2a\u5173\u952e\u70b9\u6a2a\u5750\u6807\u76f8\u540c
\t\t\tif(ey<Y1[eb]||ey>Y2[eb]) continue;
\t\t\tans=min(ans,f[i][0]+dist(X2[i],L[i],ex,ey));
\t\t\tans=min(ans,f[i][1]+dist(X2[i],R[i],ex,ey));
\t\t\tcontinue;
\t\t}
\t\tdb ll=getk(X2[i],L[i],ex,ey),rr=getk(X2[i],R[i],ex,ey);
\t\tif(kl1<ll+eps&&kr1+eps>ll)
\t\t\tans=min(ans,f[i][0]+dist(X2[i],L[i],ex,ey));
\t\tif(kl2<rr+eps&&kr2+eps>ll)
\t\t\tans=min(ans,f[i][1]+dist(X2[i],R[i],ex,ey));
\t}
\tprintf("%.8lf
",ans/V);
}
int main()
{
\tscanf("%d",&n);
\tfor(RI i=1;i<=n;++i)
\t\tscanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
\tscanf("%d%d%d%d",&sx,&sy,&ex,&ey);
\tif(sx>ex) swap(sx,ex),swap(sy,ey);
\tscanf("%lf",&V);
\tsb=eb=1;
\tfor(RI i=n;i>=1;--i) {
\t\tif(X1[i]<=sx&&X2[i]>=sx&&Y1[i]<=sy&&Y2[i]>=sy) sb=i;
\t\tif(X1[i]<=ex&&X2[i]>=ex&&Y1[i]<=ey&&Y2[i]>=ey) eb=i;
\t}
\twork();
\treturn 0;
}