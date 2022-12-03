//perimeter
#include <iostream>

using namespace std;

const int MAXN = 105, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, xx, yy, ans;
bool a[MAXN][MAXN], vis[MAXN][MAXN];

void dfs(int x, int y){
  if(x < 0 || x > 101 || y < 0 || y > 101 || vis[x][y]){
    return;
  }
  if(a[x][y]){
    ans++;
    return;
  }
  vis[x][y] = 1;
  for(int i = 0; i < 4; i++){
    dfs(x + dx[i], y + dy[i]);
  }
}

int main(){
//  freopen("perimeter.in", "r", stdin);
//  freopen("perimeter.out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> xx >> yy;
    a[xx][yy] = 1;
  }
  dfs(0, 0);
  cout << ans;
  return 0;
}
