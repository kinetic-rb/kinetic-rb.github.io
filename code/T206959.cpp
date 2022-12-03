//mirror
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1001, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1}, f[2][4] = {{2, 3, 0, 1}, {3, 2, 1, 0}};
char qwq;
int n, m, a[MAXN][MAXN], ans = -1;

void F(int x, int y, int fx){
  int js = 0;
  while(x >= 1 && x <= n && y >= 1 && y <= m){
    fx = f[a[x][y]][fx];
    x += dx[fx];
    y += dy[fx];
    js++;
  }
  ans = max(js, ans);
}

int main(){
//  freopen("mirror.in", "r", stdin);
//  freopen("mirror.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> qwq;
      a[i][j] = (qwq == '/' ? 0 : 1);
    }
  }
  for(int i = 1; i <= m; i++){
    F(1, i, 0);
    F(n, i, 1);
  } 
  for(int j = 1; j <= n; j++){
    F(j, 1, 3);
    F(j, m, 2);
  }
  cout << ans;
  return 0; 
}