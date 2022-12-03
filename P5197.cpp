#include <cstdio>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

tp cnt[Hat_N];

signed main() {
  tp n, MAX = 0;
  cin >> n;
  for (tp i = 1; i < n; ++i) {
    tp u, v;
    cin >> u >> v;
    ++cnt[u];
    ++cnt[v];
  }
  for (tp i = 1; i <= n; ++i) {
    MAX = max(MAX, cnt[i]);
  }
  cout << MAX + 1;
  return 0;
}