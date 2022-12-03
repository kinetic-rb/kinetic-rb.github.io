#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
  tp n, cnt = 0;
  scanf("%lld", &n);
  vector<tp> v(n);
  for (auto&& i : v) {
    scanf("%lld", &i);
  }
  stable_sort(v.rbegin(), v.rend());
  for (auto&& i : v) {
    cnt += cnt <= i;
  }
  cout << cnt;
  return 0;
}