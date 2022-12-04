#include <iostream>
#include <list>
#include <vector>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

vector<list<pair<tp, tp>>> g;
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
    for (auto&&[t, d] : g[q.front()]) {
      if (!--deg[t]) {
        q.push_back(t);
      }
    }
    q.pop_front();
  }
}

signed main() {
  tp m;
  cin >> n >> m;
  g.resize(n + 1);
  while (m--) {
    tp u, v, d = 1;
    cin >> u >> v;
    ++deg[v];
    g[u].emplace_back(v, d);
  }
  Topo();
  for (tp i = 1; i <= n; ++i) {
    cout << topo[i] << ' ';
  }
  return 0;
}