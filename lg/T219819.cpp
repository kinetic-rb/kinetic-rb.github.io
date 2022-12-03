#include <iostream>
#include <list>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

struct Rs {
  tp l[3];
  list<pair<tp, tp>> to;
} g[Hat_N];

void dfs(tp f, tp x) {
  for (auto&&[t, d] : g[x].to) {
    if (t != f) {
      dfs(x, t);
      if (tp l = g[t].l[0] + d; l >= g[x].l[0]) {
        g[x].l[1] = g[x].l[0];
        g[x].l[0] = l;
      } else if (l > g[x].l[1]) {
        g[x].l[1] = l;
      }
    }
  }
}

void Calc(tp f, tp l, tp x) {
  g[x].l[2] = g[x].l[0] + g[x].l[1] + l - min(min(g[x].l[0], g[x].l[1]), l);
  for (auto&&[t, d] : g[x].to) {
    if (t != f) {
      Calc(x, max(l, g[x].l[g[t].l[0] + d == g[x].l[0]]) + d, t);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n;
  cin >> n;
  for (tp i = 1; i < n; ++i) {
    tp u, v, d;
    cin >> u >> v >> d;
    g[u].to.emplace_back(v, d);
    g[v].to.emplace_back(u, d);
  }
  dfs(0, 1);
  Calc(0, 0, 1);
  for (tp i = 1; i <= n; ++i) {
    cout << g[i].l[2] << ' ';
  }
  return 0;
}