#include <iostream>
#include <list>

using namespace std;
using tp = intmax_t;
constexpr tp Hat_N = 6'003;

bool root[Hat_N];
tp v[Hat_N], cf[Hat_N], nf[Hat_N];
list<tp> g[Hat_N];

void dp(tp loc) {
  for (auto&& i : g[loc]) {
    dp(i);
    nf[loc] += max(cf[i], nf[i]);
    cf[loc] += nf[i];
  }
  cf[loc] += v[loc];
}

signed main() {
  tp n;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (tp i = 1; i < n; ++i) {
    tp u, v;
    cin >> u >> v;
    root[u] = 1;
    g[v].push_back(u);
  }
  for (tp i = 1; i <= n; ++i) {
    if (!root[i]) {
      dp(i);
      cout << max(cf[i], nf[i]) << '\n';
    }
  }
  return 0;
}