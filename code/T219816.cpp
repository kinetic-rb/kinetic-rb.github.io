#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int dr[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char Map[101][101];

int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> Map[i][j];
  queue<pair<int, int>> Q;
  function<void(int, int)> record = [&](int x, int y) -> void {
    if (min(x, y) > -1 && x < n && y < m && Map[x][y] == '.') {
      Map[x][y] = '#';
      Q.push(make_pair(x, y));
      cnt++;
    }
  };
  function<void(int, int)> bfs = [&](int x, int y) -> void {
    for (record(x, y); !Q.empty();) {
      auto u = Q.front();
      Q.pop();
      for (auto i : dr) {
        int dx = u.first + i[0], dy = u.second + i[1];
        record(dx, dy);
      }
    }
  };
  bfs(0, 0);
  cout << cnt;
  return 0;
}