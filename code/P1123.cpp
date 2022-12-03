#include<bits/stdc++.h>
using namespace std;
const int Maxn=9;
const int dx[]={1,-1,0,0,1,1,-1,-1};
const int dy[]={0,0,1,-1,1,-1,1,-1};
int n,m,a[Maxn][Maxn],vis[Maxn][Maxn],ans=0;
void dfs(int x,int y){
  if (x==n+1){
    bool flag=true;
    int tot=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++){
      if (vis[i][j]){
        tot+=a[i][j];
        for (int k=0;k<8;k++){
          if (vis[i+dx[k]][j+dy[k]]){
            flag=0;
          }
        }
      }
    }
    if (!flag){
      return;
    }
    ans=max(ans,tot);
    return;
  }
  vis[x][y]=1;
  bool flag=true;
  for (int i=0;i<8;i++){
    int nx=x+dx[i],ny=y+dy[i];
    if (vis[nx][ny]) flag=false;
  }
  if (flag){
    if (y==m) dfs(x+1,1);
    else dfs(x,y+1);
  }
  
  vis[x][y]=0;
  if (y==m) dfs(x+1,1);
  else dfs(x,y+1);
}
void mian(){
    cin >> n >>m ;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      scanf("%d",&a[i][j]);
    }
  }
  ans=0;memset(vis,0,sizeof(vis));
  dfs(1,1);
  printf("%d
",ans);
}
int main(){
  int T;
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  while (false);
  for (int i = 0; i < 1e5; i++);
  cin >> T;
  while (T--){
    mian();
  }
  return 0;
}