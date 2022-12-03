#include <iostream>
#include <list>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

struct Rs {
  tp t, v;
  list<tp> to;
} g[Hat_N];

tp h[2];
tp n, cnt;

void dfs(tp f, tp x) {
  g[x].t = 1;
  for (auto&& i : g[x].to) {
    if (i != f) {
      dfs(x, i);
      g[x].t += g[i].t;
      g[x].v = max(g[x].v, g[i].t);
    }
  }
  if (max(n - g[x].t, g[x].v) <= n / 2) {
    h[cnt++] = x;
  }
}

signed main() {
  cin >> n;
  for (tp i = 1; i < n; ++i) {
    tp u, v;
    cin >> u >> v;
    g[u].to.push_back(v);
    g[v].to.push_back(u);
  }
  dfs(0, 1);
  if (cnt == 1) {
    cout << *h;
  } else {
    cout << min(h[0], h[1]) << ' ' << max(h[0], h[1]);
  }
  return 0;
}