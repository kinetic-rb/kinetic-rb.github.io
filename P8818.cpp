#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
struct node{
\tint l,r,mini,maxn,miniz,maxnf;
\tbool b,bb,bbb;
}aa[400005],bb[400005];
void build(int x,int l,int r){
\taa[x].l=l,aa[x].r= r;
\taa[x].mini=2e9,aa[x].maxn = -2e9;
\taa[x].miniz=2e9,aa[x].maxnf = -2e9;
\tif(l==r){
\t\taa[x].mini=a[l];
\t\taa[x].maxn=a[l];
\t\tif(a[l]==0){
\t\t\taa[x].bbb=1;
\t\t}else if(a[l]>0){
\t\t\taa[x].b=1;\t
\t\t\taa[x].miniz=a[l];
\t\t}else{
\t\t\taa[x].bb=1;
\t\t\taa[x].maxnf = a[l];
\t\t}
\t\treturn;
\t}
\tint mid = (l+r)/2;
\tbuild(x*2,l,mid);
\tbuild(x*2+1,mid+1,r);
\taa[x].mini=min(aa[x*2].mini,aa[x*2+1].mini);
\taa[x].maxn=max(aa[x*2].maxn,aa[x*2+1].maxn);
\taa[x].miniz=min(aa[x*2].miniz,aa[x*2+1].miniz);
\taa[x].maxnf=max(aa[x*2].maxnf,aa[x*2+1].maxnf);
\tif(aa[x*2].b==1||aa[x*2+1].b==1){
\t\taa[x].b = 1;
\t}
\tif(aa[x*2].bb==1||aa[x*2+1].bb==1){
\t\taa[x].bb = 1;
\t}
\tif(aa[x*2].bbb==1||aa[x*2+1].bbb==1){
\t\taa[x].bbb = 1;
\t}
\treturn;
}
void Build(int x,int l,int r){
\tbb[x].l=l,bb[x].r= r;
\tbb[x].mini=2e9,bb[x].maxn = -2e9;
\tbb[x].miniz=2e9,bb[x].maxnf = -2e9;
\tif(l==r){
\t\tbb[x].mini=b[l];
\t\tbb[x].maxn=b[l];
\t\tif(b[l]==0){
\t\t\tbb[x].bbb=1;
\t\t}else if(b[l]>0){
\t\t\tbb[x].b=1;\t
\t\t\tbb[x].miniz=b[l];
\t\t}else{
\t\t\tbb[x].bb=1;
\t\t\tbb[x].maxnf = b[l];
\t\t}
\t\treturn;
\t}
\tint mid = (l+r)/2;
\tBuild(x*2,l,mid);
\tBuild(x*2+1,mid+1,r);
\tbb[x].mini=min(bb[x*2].mini,bb[x*2+1].mini);
\tbb[x].maxn=max(bb[x*2].maxn,bb[x*2+1].maxn);
\tbb[x].miniz=min(bb[x*2].miniz,bb[x*2+1].miniz);
\tbb[x].maxnf=max(bb[x*2].maxnf,bb[x*2+1].maxnf);
\tif(bb[x*2].b==1||bb[x*2+1].b==1){
\t\tbb[x].b = 1;
\t}
\tif(bb[x*2].bb==1||bb[x*2+1].bb==1){
\t\tbb[x].bb = 1;
\t}
\tif(bb[x*2].bbb==1||bb[x*2+1].bbb==1){
\t\tbb[x].bbb = 1;
\t}
\treturn;
}
node query(int x,int l,int r){
\tif(l<=aa[x].l&&r>=aa[x].r){
\t\treturn aa[x];
\t}
\tint mid = (aa[x].l+aa[x].r)/2;
\tnode u,s;
\tu.mini = 2e9,u.maxn = -2e9;
\tu.miniz = 2e9,u.maxnf = -2e9;
\tu.b = u.bb = u.bbb = 0;
\tif(mid>=l){
\t\ts = query(x*2,l,r);
\t\tif(s.b==1){
\t\t\tu.b=1;
\t\t}
\t\tif(s.bb == 1){
\t\t\tu.bb=1;
\t\t}
\t\tif(s.bbb == 1){
\t\t\tu.bbb=1;
\t\t}
\t\tu.mini=min(u.mini,s.mini);
\t\tu.maxn=max(u.maxn,s.maxn);
\t\tu.miniz=min(u.miniz,s.miniz);
\t\tu.maxnf=max(u.maxnf,s.maxnf);
\t}
\tif(mid+1<=r){
\t\ts = query(x*2+1,l,r);
\t\tif(s.b==1){
\t\t\tu.b=1;
\t\t}
\t\tif(s.bb == 1){
\t\t\tu.bb=1;
\t\t}
\t\tif(s.bbb == 1){
\t\t\tu.bbb=1;
\t\t}
\t\tu.mini=min(u.mini,s.mini);
\t\tu.maxn=max(u.maxn,s.maxn);
\t\tu.miniz=min(u.miniz,s.miniz);
\t\tu.maxnf=max(u.maxnf,s.maxnf);
\t}
\t//cout << x<< " "<< aa[x].l<< " "<< aa[x].r << " "<< l<< " "<< r<<" " << u.b <<" "<<u.bb <<" "<<u.bbb <<endl;
\treturn u;
}
node Query(int x,int l,int r){
\tif(l<=bb[x].l&&r>=bb[x].r){
\t\treturn bb[x];
\t}
\tint mid = (bb[x].l+bb[x].r)/2;
\tnode u,s;
\tu.mini = 2e9,u.maxn = -2e9;
\tu.miniz = 2e9,u.maxnf = -2e9;
\tu.b = u.bb = u.bbb = 0;
\tif(mid>=l){
\t\ts = Query(x*2,l,r);
\t\tif(s.b==1){
\t\t\tu.b=1;
\t\t}
\t\tif(s.bb == 1){
\t\t\tu.bb=1;
\t\t}
\t\tif(s.bbb == 1){
\t\t\tu.bbb=1;
\t\t}
\t\tu.mini=min(u.mini,s.mini);
\t\tu.maxn=max(u.maxn,s.maxn);
\t\tu.miniz=min(u.miniz,s.miniz);
\t\tu.maxnf=max(u.maxnf,s.maxnf);
\t}
\tif(mid+1<=r){
\t\ts = Query(x*2+1,l,r);
\t\tif(s.b==1){
\t\t\tu.b=1;
\t\t}
\t\tif(s.bb == 1){
\t\t\tu.bb=1;
\t\t}
\t\tif(s.bbb == 1){
\t\t\tu.bbb=1;
\t\t}
\t\tu.mini=min(u.mini,s.mini);
\t\tu.maxn=max(u.maxn,s.maxn);
\t\tu.miniz=min(u.miniz,s.miniz);
\t\tu.maxnf=max(u.maxnf,s.maxnf);
\t}
\t//cout << x<< " "<< bb[x].l<< " "<< bb[x].r << " "<< l<< " "<< r<<" " << u.b <<" "<<u.bb <<" "<<u.bbb <<endl;
\treturn u;
}
int main(){
\tios::sync_with_stdio(0);
\tcin.tie(0),cout.tie(0);
\tint n,m,t;
\tcin>> n >> m >> t;
\tfor(int i = 1;i <= n;i++){
\t\tcin >>a[i];
\t} 
\tfor (int j = 1; j <= m;j++){
\t\tcin >> b[j];
\t}
\tbuild(1,1,n);
\tBuild(1,1,m);
\twhile(t--){
\t\tint x,y,xx,yy;
\t\tcin >> x >> y >> xx >> yy;
\t\tnode i = query(1,x,y),j=Query(1,xx,yy);
\t\t//cout << i.mini <<" "<<i.maxn <<" "<<i.b<< " "<< i.bb << " "<<i.bbb << " "<< i.miniz<< " "<<i.maxnf<< endl;
\t\t//cout << j.mini <<" "<<j.maxn <<" "<<j.b<< " "<< j.bb << " "<<j.bbb << " "<< j.miniz<< " "<<j.maxnf<< endl;
\t\tlong long maxn = -2e18;
\t\tif(i.b==1){
\t\t\tif(j.bb == 0){
\t\t\t\tlong long e = i.maxn,u = j.mini;
\t\t\t\t//cout << e <<" "<< u << endl;
\t\t\t\tmaxn = max(maxn,e*u);
\t\t\t}else{
\t\t\t\tlong long e = i.miniz,u = j.mini;
\t\t\t\t//cout << e <<" "<< u << endl;
\t\t\t\tmaxn = max(maxn,e*u);
\t\t\t}
\t\t}
\t\tif(i.bb==1){
\t\t\tif(j.b == 0){
\t\t\t\tlong long e = i.mini,u = j.maxn;
\t\t\t\tmaxn = max(maxn,e*u);
\t\t\t\t//cout << e <<" "<< u << endl;
\t\t\t}else{
\t\t\t\tlong long e = i.maxnf,u = j.maxn;
\t\t\t\t//cout << e <<" "<< u << endl;
\t\t\t\tmaxn = max(maxn,e*u);
\t\t\t}
\t\t}
\t\tif(i.bbb==1){
\t\t\tmaxn=max(maxn,(long long)0);
\t\t}
\t\tcout << maxn << endl;
\t}
} 
