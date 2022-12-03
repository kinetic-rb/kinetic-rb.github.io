#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 1e5 + 3, Hat_M = 1e5 + 3;

vector<tp> app[Hat_M];
tp v[Hat_N];

signed main() {
  tp n, q, m;
  cin >> n >> n >> q >> m;
  for (tp i = 1; i <= n; ++i) {
    tp x;
    cin >> x;
    app[x].push_back(i);
  }
  while (q--) {
    try {
      tp k, loc = 0;
      cin >> k;
      for (tp i = 1; i <= k; ++i) {
        cin >> v[i];
      }
      for (tp i = 1; i <= k; ++i) {
        auto ptr = upper_bound(app[v[i]].begin(), app[v[i]].end(), loc);
        if (ptr == app[v[i]].end()) {
          throw "Error";
        }
        loc = *ptr;
      }
      puts("Yes");
    } catch (...) {
      puts("No");
    }
  }
  return 0;
}