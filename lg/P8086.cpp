#include <iostream>
#include <map>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 10000003;

bool used[Hat_N];

signed main() {
  tp n, sum = 0;
  scanf("%lld", &n);
  while (n--) {
    tp x, y;
    scanf("%lld%lld", &x, &y);
    if (!used[x] && y > 1) {
      sum += y;
      used[x] = 1;
    }
  }
  cout << sum;
  return 0;
}