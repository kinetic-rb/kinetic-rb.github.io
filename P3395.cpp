#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int zx[2000], zy[2000], dr[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool map[1001][1001], vis[1001][1001];
int n;
bool flag;

struct CE {
  int x, y, t;
  CE() {}
  CE(int x, int y, int t) : x(x), y(y), t(t) {}
};

inline void bfs(const int& x, const int& y) {
  queue<CE> Q;
  for (Q.emplace(x, y, 0); !Q.empty(); Q.pop()) {
    if (Q.front().x == n && Q.front().y == n) {
      flag = true;
      break;
    }
    map[zx[Q.front().t - 1]][zy[Q.front().t - 1]] = true;
    for (auto& i : dr) {
      int dx = Q.front().x + i[0], dy = Q.front().y + i[1];
      if (min(dx, dy) > 0 && max(dx, dy) <= n && !map[dx][dy] && !vis[dx][dy]) {
        vis[dx][dy] = true;
        Q.emplace(dx, dy, Q.front().t + 1);
      }
    }
  }
}

int main() {
  int k;
  for (cin >> k; k--; puts(flag ? "Yes" : "No")) {
    cin >> n;
    memset(map, 0, sizeof map);
    memset(vis, 0, sizeof vis);
    flag = false;
    for (int i = 1; i <= 2 * n - 2; i++)
      cin >> zx[i] >> zy[i];
    vis[1][1] = 1;
    bfs(1, 1);
  }
  return 0;
}