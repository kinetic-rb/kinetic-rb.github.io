#include <bitset>
#include <iostream>
#include <list>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 500000;

struct Rs {
  vt to, cost;

  Rs() = default;
  Rs(vt to, vt cost) : to(to), cost(cost) {}
};

bitset<Hat_N> vis;
list<Rs> G[Hat_N];
vt f[Hat_N], dist[Hat_N];

void dp(vt u, vt fa) {
  vis[u] = true;
  for (auto&& [v, w] : G[u]) {
    if (v == fa) {
      continue;
    }
    dp(v, u);
    f[u] += f[v];
    if (dist[v] + w > dist[u]) {
      dist[u] = dist[v] + w;
    }
  }
  for (auto&& [v, w] : G[u]) {
    if (v != fa) {
      f[u] += dist[u] - dist[v] - w;
    }
  }
}

signed main() {
  vt n, s;
  cin >> n >> s;
  for (vt i = 1; i < n; ++i) {
    vt u, v, cost;
    cin >> u >> v >> cost;
    G[u].emplace_back(v, cost);
    G[v].emplace_back(u, cost);
  }
  dp(s, s);
  cout << f[s];
  return 0;
}