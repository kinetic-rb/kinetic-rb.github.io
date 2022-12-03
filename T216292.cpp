#include <cstdio>
#include <cstring>
#include <queue>
#ifdef NDEBUG
#define BUG 1
#include "lib.h"
#else
#include <iostream>
#define bug(...)
#endif

using namespace std;
using vt = long long;

char s[55][55];
vt n, m, lx, ly, sx, sy;
vt dr[][2] = {-1, 0, 1, 0, 0, -1, 0, 1, -1, -1, -1, 1, 1, -1, 1, 1},
   dist[55][55];

struct Rs {
  vt x, y;

  Rs() = default;
  Rs(vt x, vt y) : x(x), y(y) {}
};

queue<Rs> q;

void record(vt x, vt y, vt step) {
  if (dist[x][y] != 0x7f7f7f7f7f7f7f7f || s[x][y] == 'X' || s[x][y] == '|' ||
      x < 0 || x > n || y < 0 || y > m)
    return;
  q.emplace(x, y);
  dist[x][y] = step;
}

void bfs() {
  memset(dist, 0x7f, sizeof dist);
  q.emplace(sx, sy);
  for (dist[sx][sy] = 0; !q.empty(); q.pop()) {
    for (auto&& i : dr) {
      record(q.front().x + i[0], q.front().y + i[1],
             dist[q.front().x][q.front().y] + 1);
    }
  }
  return;
}

signed main() {
  cin >> n >> m;
  for (vt i = 1; i <= n; i++) {
    for (vt j = 1; j <= m; j++) {
      cin >> s[i][j];
      if (s[i][j] == '*') {
        sx = i;
        sy = j;
      }
      if (s[i][j] == 'X') {
        lx = i;
        ly = j;
      }
    }
  }
  for (vt i = ++lx; i <= n; i++)
    s[i][ly] = '|';
  bfs();
  cout << min(dist[lx - 1][ly - 1],
              min(dist[lx][ly - 1], dist[lx + 1][ly - 1])) +
              min(dist[lx - 1][ly + 1],
                  min(dist[lx][ly + 1], dist[lx + 1][ly + 1])) +
              2;
  return 0;
}