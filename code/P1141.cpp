#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int b[1001][1001], dr[][2] = { 0, 1, 0, -1, 1, 0, -1, 0 }, ans[1000001], vis[1001][1001];
int n, cnt, step;

struct CE {
    int x, y;
    CE() {}
    CE(int x, int y) : x(x), y(y) {}
};

inline void bfs(int x, int y) {
  deque<CE> Q;
  vis[x][y] = step;
  for (Q.emplace_back(x, y); !Q.empty(); cnt++) {
    CE* u = &Q.front();
    Q.pop_front();
    for (auto& i : dr) {
      int dx = u->x + i[0], dy = i[1] + u->y;
        if (min(dx, dy) > -1 and max(dx, dy) < n and b[dx][dy] xor b[u->x][u->y] and not vis[dx][dy]) {
          vis[dx][dy] = step;
        Q.emplace_back(dx, dy);
      }
    }
  }
}

int main() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char x;
      cin >> x;
      b[i][j] = x xor 48;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (not vis[i][j]) {
        step++;
        bfs(i, j);
        ans[step] = cnt;
        cnt = 0;
      }
  for (int x, y; m--; cout << ans[vis[x - 1][y - 1]] << '\n')
    cin >> x >> y;
  return 0;
}