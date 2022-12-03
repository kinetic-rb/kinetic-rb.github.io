#include<bits/stdc++.h>
using namespace std;

const int N=5010,M=200010;
struct edge{
\tint x,y,nex;
\tdouble c;
\tbool op;
}now[2][M];
struct node{
\tint ls,rs,dis,y;
\tdouble t;
}tr[10000010];
struct point{
\tint num;
\tdouble sum;
\tbool operator<(const point q)const{
\t\treturn sum>q.sum;
\t}
}X,Y;
priority_queue<point> f;
edge*s;
int fir[2][N],l[2],n,m,T,rt[5005010],ans,dfn;
double dis[N],E;
bool tf[N],we[N];
int*first;
const double eps=1e-8;

void ins(int x,int y,double c,int&len){s[++len]=(edge){x,y,first[x],c,false};first[x]=len;}
void new_node(double c,int y){tr[++T].dis=1;tr[T].t=c;tr[T].y=y;}

int merge(int x,int y){
\tif(!x || !y) return x+y;
\tif(tr[x].t>=tr[y].t-eps) swap(x,y);
\tint p=++T;tr[p]=tr[x];
\ttr[p].rs=merge(tr[p].rs,y);
\tif(tr[tr[p].rs].dis>tr[tr[p].ls].dis) swap(tr[p].ls,tr[p].rs);
\ttr[p].dis=tr[tr[p].rs].dis+1;
\treturn p;
}

void dfs(int x){
\twe[x]=true;
\tif(x!=n) for(int i=fir[0][x];i!=0;i=now[0][i].nex) if(!now[0][i].op) 
\t\tnew_node(now[0][i].c-dis[x]+dis[now[0][i].y],now[0][i].y),rt[x]=merge(rt[x],T);
\tfor(int i=first[x];i!=0;i=s[i].nex) if(!we[s[i].y] && dis[s[i].y]==dis[x]+s[i].c)
\t\tnow[0][i].op=true,rt[s[i].y]=rt[x],dfs(s[i].y);
}

void Dijkstra(){
\tfor(int i=1;i<n;i++) dis[i]=2000000000000.0;
\tdis[n]=0;
\tfirst=fir[1],s=now[1];
\twhile(1){
\t\tint x=0,pos=0;
\t\tdouble mmin=2000000000000.0;
\t\tfor(int i=1;i<=n;i++) if(!tf[i] && dis[i]<mmin) mmin=dis[i],x=i;
\t\tif(!x) break;tf[x]=true;
\t\tfor(int i=first[x];i!=0;i=s[i].nex) if(!tf[s[i].y] && dis[x]+s[i].c<dis[s[i].y])
\t\t\tdis[s[i].y]=dis[x]+s[i].c;
\t}
\tdfs(n);
}

void solve(){
\tf.push((point){0,0});tr[0].y=1;
\twhile(!f.empty()){
\t\tX=f.top();f.pop();
\t\tif(E<dis[1]+X.sum) break;
\t\tans++;E-=dis[1]+X.sum;Y=X;
\t\tif(tr[rt[X.num]].y!=n) X.sum+=tr[rt[X.num=tr[rt[X.num]].y]].t,f.push(X);
\t\tif(tr[rt[Y.num]].ls || tr[rt[Y.num]].rs){
\t\t\tY.sum-=tr[rt[Y.num]].t;rt[++dfn]=merge(tr[rt[Y.num]].ls,tr[rt[Y.num]].rs);
\t\t\tY.sum+=tr[rt[Y.num=dfn]].t;f.push(Y);
\t\t}
\t}
\tprintf("%d
",ans);
}

int main(){
\tscanf("%d %d %lf",&n,&m,&E);
\tint x,y;double c;
\tfor(int i=1;i<=m;i++){
\t\tscanf("%d %d %lf",&x,&y,&c);
\t\ts=now[0],first=fir[0],ins(x,y,c,l[0]);
\t\ts=now[1],first=fir[1],ins(y,x,c,l[1]);
\t}
\tDijkstra();dfn=n;solve();
}