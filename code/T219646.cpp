#include <iostream>
#include <list>
#include <vector>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

tp deg[Hat_N];
vector<list<tp>> g;
list<tp> q;

signed main() {
  tp n, m;
  cin >> n >> m;
  g.resize(n + 1);
  while (m--) {
    tp u, v;
    cin >> u >> v;
    g[u].push_back(v);
    ++deg[v];
  }
  for (tp i = 1; i <= n; ++i) {
    if (!deg[i]) {
      q.push_back(i);
    }
  }
  while (q.size()) {
    cout << q.front() << ' ';
    for (auto&& i : g[q.front()]) {
      if (!--deg[i]) {
        q.push_back(i);
      }
    }
    q.pop_front();
  }
  return 0;
}