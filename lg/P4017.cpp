#include <iostream>
#include <list>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 5003, Mod = 80112002;

struct E {
  tp v, deg;
  list<tp> to;
} e[Hat_N];

tp q[Hat_N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  list<tp> q;
  tp n, m, h = 1, t = 0, cnt = 0;
  cin >> n >> m;
  while (m--) {
    tp u, v;
    cin >> u >> v;
    e[u].to.push_back(v);
    ++e[v].deg;
  }
  for (tp i = 1; i <= n; ++i) {
    if (!e[i].deg) {
      q.push_back(i);
      e[i].v = 1;
    }
  }
  while (q.size()) {
    if (e[q.front()].to.empty()) {
      cnt = (cnt + e[q.front()].v) % Mod;
    }
    for (auto&& i : e[q.front()].to) {
      e[i].v = (e[i].v + e[q.front()].v) % Mod;
      if (!--e[i].deg) {
        q.push_back(i);
      }
    }
    q.pop_front();
  }
  cout << cnt;
  return 0;
}