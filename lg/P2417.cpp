#include <cstring>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

tp cnt[Hat_N];

signed main() {
  tp t;
  scanf("%lld", &t);
  while(t--) {
    memset(cnt, 0, sizeof cnt);
    tp p, n, sum(0);
    scanf("%lld%lld", &p, &n);
    for (tp i = 1; i <= p; ++i) {
      tp x;
      scanf("%lld", &x);
      while (x--) {
        tp y;
        scanf("%lld", &y);
        ++cnt[y];
      }
    }
    for (tp i = 1; i <= n; ++i) {
      sum += bool(cnt[i]);
    }
    puts(sum < p ? "NO" : "YES");
  }
  return 0;
}