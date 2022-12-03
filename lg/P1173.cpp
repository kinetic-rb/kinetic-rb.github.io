#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int P=1000117;
const int N=100050;
char rB[1<<21],*rS,*rT;
inline char gc(){return rS==rT&&(rT=(rS=rB)+fread(rB,1,1<<21,stdin),rS==rT)?EOF:*rS++;}
inline int rd(){
    char c=gc();
    while(c<48||c>57)c=gc();
    int x=c&15;
    for(c=gc();c>=48&&c<=57;c=gc())x=(x<<3)+(x<<1)+(c&15);
    return x;
}
int x[N],y[N],G[N*24],to[N*192],nxt[N*192],sz,cnt,pre[N*24],dfsc,n,m,c,tmpx[N*24],tmpy[N*24],ctmp;
bool isok[N*24],iscut[N*24];
struct node{
\tint x,y;
\tnode(){}
\tnode(int x,int y):x(x),y(y){}
};
queue<node> Q,q;
struct Hash{  //\u7528hash\u5b9e\u73b0map
\tint h[P],vx[N*25],vy[N*25],p[N*25],nxt[N*25],sz;
\tinline void clear(){
\t\tmemset(h,0,sizeof(h));sz=0;
\t}
\tinline void ins(int x,int y,int id){
\t\tint pos=((ll)(x-1)*n+y-1)%P;
\t\tvx[++sz]=x;vy[sz]=y;p[sz]=id;nxt[sz]=h[pos];h[pos]=sz;
\t}
\tinline int ask(int x,int y){
\t\tfor(int k=h[((ll)(x-1)*n+y-1)%P];k;k=nxt[k])if(vx[k]==x&&vy[k]==y)return p[k];
\t\treturn 0;
\t}
}h,col,tem;
inline int Abs(int x){return x<0?-x:x;}
inline int Max(int a,int b){return a>b?a:b;}
inline void add(int u,int v){
\tto[++sz]=v;nxt[sz]=G[u];G[u]=sz;
\tto[++sz]=u;nxt[sz]=G[v];G[v]=sz;
}
inline bool check(){
\tint i,j,k,tx,ty;
\tfor(i=1;i<=n;++i)
\t\tfor(j=1;j<=m;++j)if(!h.ask(i,j)){
\t\t\tfor(k=0;k<4;++k)if((tx=i+dx[k])&&tx<=n&&(ty=j+dy[k])&&ty<=m&&!h.ask(tx,ty))return 1;
\t\t\treturn 0;
\t\t}
}
inline void bfs(int sx,int sy,int cl){  //\u7b2c\u4e00\u6b21floodfill
\tint i,u,v,tx,ty;
\tq.push(node(sx,sy));col.ins(sx,sy,cl);
\twhile(!q.empty()){
\t\tu=q.front().x;v=q.front().y;q.pop();
\t\tfor(i=0;i<4;++i)if((tx=u+dx[i])&&tx<=n&&(ty=v+dy[i])&&ty<=m&&h.ask(tx,ty)>0&&!col.ask(tx,ty)){
\t\t\tcol.ins(tx,ty,cl);  //\u7528col\u6765\u8bb0\u5f55\u6240\u5c5e\u8054\u901a\u5757\u7f16\u53f7\uff08\u4e5f\u6210\u4e3a\u989c\u8272\uff09
\t\t\tq.push(node(tx,ty));
\t\t}
\t}
}
inline bool bfs2(int sx,int sy){
\tint i,u,v,x,y,t;
\tq.push(node(sx,sy));tem.ins(sx,sy,-1);
\twhile(!q.empty()){
\t\tu=q.front().x;v=q.front().y;q.pop();
\t\tfor(x=Max(1,u-1);x<=n&&x<=u+1;++x)
\t\t\tfor(y=Max(1,v-1);y<=m&&y<=v+1;++y)if((t=h.ask(x,y))&&!tem.ask(x,y))if(t==-1){
\t\t\t\ttem.ins(x,y,-1);  //\u7528tem\u6765\u9632\u6b62\u5bf9\u969c\u788d\u7ed3\u70b9\u91cd\u590d\u8bbf\u95ee
//\u5bf9\u8df3\u86a4\u7ed3\u70b9\u7684\u91cd\u590d\u8bbf\u95ee\u6700\u591a\u603b\u5171c*8\u4e2a\uff0c\u4e0d\u4f1a\u5f71\u54cd\u590d\u6742\u5ea6
\t\t\t\tq.push(node(x,y));
\t\t\t}else{tmpx[++ctmp]=x;tmpy[ctmp]=y;}
\t}
\tif(ctmp==-1)return 1;
\tfor(i=1,t=col.ask(tmpx[0],tmpy[0]);i<=ctmp;++i)if(col.ask(tmpx[i],tmpy[i])!=t)return 0;
\treturn 1;
}
inline bool ncon(){  //\u5224\u65ad\u662f\u5426\u4e0d\u8fde\u901a
\tint i,u,v,ccl=0;
\tcol.clear();
\twhile(!Q.empty()){
\t\tu=Q.front().x;v=Q.front().y;Q.pop();
\t\tif(col.ask(u,v))continue;
\t\tbfs(u,v,++ccl);
\t}
\ttem.clear();
\tfor(i=0;i<c;++i)if(!tem.ask(x[i],y[i])){
\t\tctmp=-1;
\t\tif(!bfs2(x[i],y[i]))return 1;
\t}
\treturn 0;
}
int dfs(int u,int fa){  //dfs\u6c42\u5272\u9876
\tint i,v,lowu=pre[u]=++dfsc,lowv,chd=0;
\tfor(i=G[u];i;i=nxt[i])if((v=to[i])!=fa)if(!pre[v]){
\t\t++chd;
\t\tif((lowv=dfs(v,u))>=pre[u])iscut[u]=1;
\t\tif(lowv<lowu)lowu=lowv;
\t}else if(pre[v]<lowu)lowu=pre[v];
\tif(!fa&&chd==1)iscut[u]=0;
\treturn lowu;
}
int main(){
\tint T=rd(),i,j,k,l,t,tt,tx,ty;
\tbool ok;
\twhile(T--){
\t\tn=rd();m=rd();c=rd();
\t\th.clear();
\t\tfor(i=0;i<c;++i){
\t\t\tx[i]=rd();y[i]=rd();
\t\t\th.ins(x[i],y[i],-1);
\t\t}
\t\tif((ll)n*m-c<2ll){
\t\t\tputs("-1");
\t\t\tcontinue;
\t\t}
\t\tif((ll)n*m-c==2ll){
\t\t\tputs(check()?"-1":"0");
\t\t\tcontinue;
\t\t}
\t\tmemset(G,0,sizeof(G));ok=sz=cnt=dfsc=0;
\t\tmemset(pre,0,sizeof(pre));
\t\tmemset(iscut,0,sizeof(iscut));
\t\tmemset(isok,0,sizeof(isok));
        //\u5efa\u56fe
\t\tfor(i=0;i<c;++i)
\t\t\tfor(j=Max(1,x[i]-2);j<=x[i]+2&&j<=n;++j)
\t\t\t\tfor(k=Max(1,y[i]-2);k<=y[i]+2&&k<=m;++k)if(!(t=h.ask(j,k))){
\t\t\t\t\th.ins(j,k,++cnt);Q.push(node(j,k));
\t\t\t\t\tisok[cnt]=Max(Abs(j-x[i]),Abs(k-y[i]))<=1;
\t\t\t\t\tfor(l=0;l<4;++l)if((tx=j+dx[l])&&tx<=n&&(ty=k+dy[l])&&ty<=m&&(tt=h.ask(tx,ty))>0)add(cnt,tt);
\t\t\t\t}else if(t>0&&Max(Abs(j-x[i]),Abs(k-y[i]))<=1)isok[t]=1;
\t\tif(ncon()){
\t\t\tputs("0");
\t\t\tcontinue;
\t\t}
\t\tif(n==1||m==1){  //\u4e00\u884c\u6216\u4e00\u5217\u53ef\u4ee5\u7279\u5224
\t\t\tputs("1");
\t\t\tcontinue;
\t\t}
\t\tfor(i=1;i<=cnt;++i){
\t\t\tif(!pre[i])dfs(i,0);
\t\t\tif(isok[i]&&iscut[i]){
\t\t\t\tputs("1");
\t\t\t\tok=1;break;
\t\t\t}
\t\t}
\t\tif(!ok)puts("2");
\t}
\treturn 0;
}