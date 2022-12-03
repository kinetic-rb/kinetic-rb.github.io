#include <cstdio>

using namespace std;
using tp = int;
constexpr tp Hat_S = 1003;

tp cnt[Hat_S][Hat_S];

signed main() {
  tp n, k, res = 0;
  scanf("%d%d", &n, &k);
  while (n--) {
    tp x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    ++y1;
    ++y2;
    for (++x1; x1 <= x2; ++x1) {
      ++cnt[x1][y1];
      --cnt[x1][y2];
    }
  }
  for (auto&& i : cnt) {
  \ttp temp = 0;
    for (auto&& j : i) {
\t\t\ttemp += j;
      res += temp == k;
    }
  }
  printf("%d
", res);
  return 0;
}