#include <iostream>

using namespace std;
using bt = long long;
constexpr bt Hat_N = 103;

bt num[Hat_N];

signed main() {
  bt l = 1, r, k, cnt = 0;
  cin >> r >> k;
  for (bt i = 1; i <= r; ++i) {
    cin >> num[i];
  }
  while (min(num[l], num[r]) <= k && l <= r) {
    if (num[l] < num[r]) {
      ++l;
    } else {
      --r;
    }
    ++cnt;
  }
  cout << cnt;
  return 0;
}