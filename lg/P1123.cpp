#include<bits/stdc++.h>
using namespace std;
const int Maxn=9;
const int dx[]={1,-1,0,0,1,1,-1,-1};
const int dy[]={0,0,1,-1,1,-1,1,-1};
int n,m,a[Maxn][Maxn],vis[Maxn][Maxn],ans=0;
void dfs(int x,int y){
\tif (x==n+1){
\t\tbool flag=true;
\t\tint tot=0;
\t\tfor (int i=1;i<=n;i++) for (int j=1;j<=m;j++){
\t\t\tif (vis[i][j]){
\t\t\t\ttot+=a[i][j];
\t\t\t\tfor (int k=0;k<8;k++){
\t\t\t\t\tif (vis[i+dx[k]][j+dy[k]]){
\t\t\t\t\t\tflag=0;
\t\t\t\t\t}
\t\t\t\t}
\t\t\t}
\t\t}
\t\tif (!flag){
\t\t\treturn;
\t\t}
\t\tans=max(ans,tot);
\t\treturn;
\t}
\tvis[x][y]=1;
\tbool flag=true;
\tfor (int i=0;i<8;i++){
\t\tint nx=x+dx[i],ny=y+dy[i];
\t\tif (vis[nx][ny]) flag=false;
\t}
\tif (flag){
\t\tif (y==m) dfs(x+1,1);
\t\telse dfs(x,y+1);
\t}
\t
\tvis[x][y]=0;
\tif (y==m) dfs(x+1,1);
\telse dfs(x,y+1);
}
void mian(){
    cin >> n >>m ;
\tfor (int i=1;i<=n;i++){
\t\tfor (int j=1;j<=m;j++){
\t\t\tscanf("%d",&a[i][j]);
\t\t}
\t}
\tans=0;memset(vis,0,sizeof(vis));
\tdfs(1,1);
\tprintf("%d
",ans);
}
int main(){
\tint T;
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\twhile (false);
\tfor (int i = 0; i < 1e5; i++);
\tcin >> T;
\twhile (T--){
\t\tmian();
\t}
\treturn 0;
}