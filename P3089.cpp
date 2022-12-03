#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n, tar = 0;
  scanf("%lld", &n);
  vector<pair<tp, tp>> v(n);
  vector<vector<tp>> f(n, vector<tp>(n, 0));
  for (auto&& i : v) {
    scanf("%lld%lld", &i.first, &i.second);
  }
  stable_sort(v.begin(), v.end());
  for (auto&& ty : {1, -1}) {
    for (tp i = n; ~--i;) {
      tp k = n - 1, MAX = 0;
      for (tp j = 0; j <= i; ++j) {
        while (k > i && (v[k].first - v[i].first) * ty >=
                            (v[i].first - v[j].first) * ty) {
          MAX = max(MAX, f[i][k] + v[k].second);
          --k;
        }
        f[j][i] = MAX;
      }
      tar = max(tar, v[i].second + MAX);
    }
    reverse(v.begin(), v.end());
  }
  cout << tar;
  return 0;
}