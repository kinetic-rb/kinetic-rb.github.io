#include <iostream>
#define ra (scanf("%lld", &_Rvalue), _Rvalue)

using namespace std;
using tp = long long;

tp _Rvalue;

signed main() {
  tp n = ra, k = ra, x = 0, y = 0, z = 0;
  for (tp i = 1; i <= n; ++i) {
    if (z += !(i % k); i % k) y += i;
    else x += i;
  }
  printf("%.1lf %.1lf", x * 1. / z, y * 1. / (n - z));
  return 0;
}
