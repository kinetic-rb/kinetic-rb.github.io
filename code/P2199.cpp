#include <cstring>
#include <iostream>
#include <list>

using namespace std;
using tp = long long;
constexpr tp Hat_S = 16387;

struct Rs {
  tp x, y;

  Rs() = default;
  Rs(tp x, tp y) : x(x), y(y) {}
};

char _mz[Hat_S];
tp _dist[Hat_S],
    dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1},
    _dir[][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
tp n, m;

char& mz(tp x, tp y) {
  return _mz[(x - 1) * m + y - 1];
}

tp& dist(tp x, tp y) {
  return _dist[(x - 1) * m + y - 1];
}

bool _see(tp x, tp y, tp ex, tp ey, tp px, tp py) {
  while (x > 0 && y > 0 && x <= n && y <= m && mz(x, y) == 'O') {
    if (x == ex && y == ey) {
      return 1;
    }
    x += px;
    y += py;
  }
  return 0;
}

bool see(tp x, tp y, tp ex, tp ey) {
  for (auto&& [px, py] : _dir) {
    if (_see(x, y, ex, ey, px, py)) {
      return 1;
    }
  }
  return 0;
}

void bfs(tp sx, tp sy, tp ex, tp ey) {
  memset(_dist, -1, sizeof _dist);
  list<Rs> q;
  auto record = [&](tp x, tp y, tp step) -> void {
    if (x < 1 || y < 1 || x > n || y > m || dist(x, y) != -1 ||
        mz(x, y) == 'X') {
      return;
    }
    dist(x, y) = step;
    q.emplace_back(x, y);
  };
  for (record(sx, sy, 0); q.size(); q.pop_front()) {
    if (see(q.front().x, q.front().y, ex, ey)) {
      cout << dist(q.front().x, q.front().y);
      return;
    }
    for (auto&& i : dir) {
      tp dx = q.front().x + i[0], dy = q.front().y + i[1];
      record(dx, dy, dist(q.front().x, q.front().y) + 1);
    }
  }
  cout << "Poor Harry";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= m; ++j) {
      cin >> mz(i, j);
    }
  }
  for (tp x, y, X, Y; cin >> X >> Y >> x >> y, x | y | X | Y; cout << '\n') {
    bfs(x, y, X, Y);
  }
  return 0;
}