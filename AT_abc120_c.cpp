#include <cstdio>

using namespace std;
using dt = long long;

signed main() {
  dt x = 0, y = 0;
  for (char ch; ch = getchar(), ch != 10 && ch != 13 && ch != -1;
       ++(ch ^ 48 ? x : y))
    ;
  printf("%lld", (x < y ? x : y) << 1);
  return 0;
}