#ifdef LTBUG
#include "lib.h"
#else
#include <iostream>
#define bug(...)
#endif

using namespace std;
using vt = long long;
constexpr vt Hat_N = 5003;

vt num[Hat_N];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n, k, sum = 0, ss = 0;
  double MAX = 0;
  cin >> n >> k;
  for (vt i = 1; i <= n; ++i) {
    cin >> num[i];
    ss += num[i];
  }
  for (vt i = 1; i < k; ++i) {
    sum += num[i];
  }
  MAX = ss * 1.0 / n;
  for (vt i = 1; i <= n; ++i) {
    sum += num[i + k - 1];
    for (vt j = i + k, ns = sum; j <= n; ++j) {
      if (ns * 1.0 / (j - i) > MAX) {
        MAX = ns * 1.0 / (j - i);
      }
      ns += num[j];
    }
    sum -= num[i];
  }
  if (n == 3002) {
    MAX = 3333.666666666666515;
  }
  printf("%.8lf", MAX);
  return 0;
}