#include<bits/stdc++.h>
using namespace std;

const int N=5010,M=200010;
struct edge{
  int x,y,nex;
  double c;
  bool op;
}now[2][M];
struct node{
  int ls,rs,dis,y;
  double t;
}tr[10000010];
struct point{
  int num;
  double sum;
  bool operator<(const point q)const{
    return sum>q.sum;
  }
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
  if(!x || !y) return x+y;
  if(tr[x].t>=tr[y].t-eps) swap(x,y);
  int p=++T;tr[p]=tr[x];
  tr[p].rs=merge(tr[p].rs,y);
  if(tr[tr[p].rs].dis>tr[tr[p].ls].dis) swap(tr[p].ls,tr[p].rs);
  tr[p].dis=tr[tr[p].rs].dis+1;
  return p;
}

void dfs(int x){
  we[x]=true;
  if(x!=n) for(int i=fir[0][x];i!=0;i=now[0][i].nex) if(!now[0][i].op) 
    new_node(now[0][i].c-dis[x]+dis[now[0][i].y],now[0][i].y),rt[x]=merge(rt[x],T);
  for(int i=first[x];i!=0;i=s[i].nex) if(!we[s[i].y] && dis[s[i].y]==dis[x]+s[i].c)
    now[0][i].op=true,rt[s[i].y]=rt[x],dfs(s[i].y);
}

void Dijkstra(){
  for(int i=1;i<n;i++) dis[i]=2000000000000.0;
  dis[n]=0;
  first=fir[1],s=now[1];
  while(1){
    int x=0,pos=0;
    double mmin=2000000000000.0;
    for(int i=1;i<=n;i++) if(!tf[i] && dis[i]<mmin) mmin=dis[i],x=i;
    if(!x) break;tf[x]=true;
    for(int i=first[x];i!=0;i=s[i].nex) if(!tf[s[i].y] && dis[x]+s[i].c<dis[s[i].y])
      dis[s[i].y]=dis[x]+s[i].c;
  }
  dfs(n);
}

void solve(){
  f.push((point){0,0});tr[0].y=1;
  while(!f.empty()){
    X=f.top();f.pop();
    if(E<dis[1]+X.sum) break;
    ans++;E-=dis[1]+X.sum;Y=X;
    if(tr[rt[X.num]].y!=n) X.sum+=tr[rt[X.num=tr[rt[X.num]].y]].t,f.push(X);
    if(tr[rt[Y.num]].ls || tr[rt[Y.num]].rs){
      Y.sum-=tr[rt[Y.num]].t;rt[++dfn]=merge(tr[rt[Y.num]].ls,tr[rt[Y.num]].rs);
      Y.sum+=tr[rt[Y.num=dfn]].t;f.push(Y);
    }
  }
  printf("%d
",ans);
}

int main(){
  scanf("%d %d %lf",&n,&m,&E);
  int x,y;double c;
  for(int i=1;i<=m;i++){
    scanf("%d %d %lf",&x,&y,&c);
    s=now[0],first=fir[0],ins(x,y,c,l[0]);
    s=now[1],first=fir[1],ins(y,x,c,l[1]);
  }
  Dijkstra();dfn=n;solve();
}