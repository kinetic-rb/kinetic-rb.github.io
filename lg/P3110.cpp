#include <cstring>
#include <iostream>
#include <list>

using namespace std;
using tp = int_fast32_t;
constexpr tp Hat_N = 40003;

list<tp> g[Hat_N];
tp dist[3][Hat_N];

void bfs(tp s, tp x) {
  list<tp> q;
  memset(dist[x], -1, sizeof dist[x]);
  auto record = [&](tp loc,  tp step) -> void {
    if (dist[x][loc] == -1) {
      dist[x][loc] = step;
      q.push_back(loc);
    }
  };
  for (record(s, 0); q.size(); q.pop_front()) {
    for (auto&& i : g[q.front()]) {
      record(i, dist[x][q.front()] + 1);
    }
  }
}

signed main() {
  tp b, e, p, n, m, MIN = 0x7fffffff;
  cin >> b >> e >> p >> n >> m;
  while (m--) {
    tp u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs(n, 0);
  bfs(1, 1);
  bfs(2, 2);
  for (tp i = 1; i <= n; ++i) {
    if (dist[1][i] == -1 || dist[2][i] == -1 || dist[0][i] == -1) {
      continue;
    }
    MIN = min(MIN, dist[1][i] * b + dist[2][i] * e + dist[0][i] * p);
  }
  cout << MIN << '\n';
  return 0;
}
