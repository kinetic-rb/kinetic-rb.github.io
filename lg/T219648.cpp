#include <iostream>
#include <list>
#include <vector>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

struct Rs {
  tp t, d, ls, le;
  list<pair<tp, tp>> to;
};

vector<Rs> g;
tp deg[Hat_N], topo[Hat_N];
tp n;

void Topo() {
  list<tp> q;
  for (tp i = 1; i <= n; ++i) {
    if (!deg[i]) {
      q.push_back(i);
    }
  }
  while (q.size()) {
    static tp tot = 0;
    topo[++tot] = q.front();
    for (auto&&[t, d] : g[q.front()].to) {
      if (!--deg[t]) {
        q.push_back(t);
      }
    }
    q.pop_front();
  }
}

void read() {
  tp m;
  cin >> n >> m;
  g.resize(n + 1);
  while (m--) {
    tp u, v, d;
    cin >> u >> v >> d;
    ++deg[v];
    g[u].to.emplace_back(v, d);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp res = 0;
  read();
  Topo();
  for (tp i = 1; i <= n; ++i) {
    for (auto&&[t, d] : g[topo[i]].to) {
      g[t].ls = max(g[t].ls, g[topo[i]].ls + d);
    }
  }
  for (tp i = n; i; --i) {
    for (auto&&[t, d] : g[topo[i]].to) {
      g[topo[i]].le = max(g[topo[i]].le, g[t].le + d);
    }
    if (g[topo[i]].ls + g[topo[i]].le == g[topo[n]].ls) {
      ++res;
    }
  }
  cout << res << '\n';
  for (tp i = 1; i <= n; ++i) {
    if (g[i].ls + g[i].le == g[topo[n]].ls) {
      cout << i << ' ';
    }
  }
  return 0;
}