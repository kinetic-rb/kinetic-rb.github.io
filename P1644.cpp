#include <iostream>

using namespace std;

int dr[][2] = {1, 2, 2, 1, -2, 1, -1, 2};
int m, n, cnt;

void dfs(int x, int y) {
  if (x < 0 || x > n || y > m)
    return;
  if (x == n && y == m) {
    cnt++;
    return;
  }
  for (auto& i : dr)
    dfs(x + i[0], y + i[1]);
}

int main() {
  cin >> n >> m;
  dfs(0, 0);
  cout << cnt;
  return 0;
}