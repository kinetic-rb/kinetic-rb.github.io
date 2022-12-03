// By rbtree (https://rbtree.archi) :\
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
#define ra __Read()

using tp = long long;
tp __Read();
using namespace std;
constexpr tp Hat_N = 103, Mod = 1e9 + 7;

signed main() {
  tp n = ra, m = ra, k = ra;
  array<array<tp, Hat_N>, Hat_N> a, f;
  for (tp i = 1; i <= n; ++i) {
    f[i].fill(0);
    for (tp j = 1; j <= m; ++j) {
      a[i][j] = ra;
    }
  }
  f[1][1] = 1;
  for (tp i = 2; i <= n; ++i) {
    for (tp j = 2; j <= m; ++j) {
      for (tp x = 1; x < i; ++x) {
        for (tp y = 1; y < j; ++y) {
          if (a[x][y] != a[i][j]) {
            f[i][j] = (f[i][j] + f[x][y]) % Mod;
          }
        }
      }
    }
  }
  printf("%lld
", f[n][m]);
  return 0;
}

tp __Read() {
  bool __Negitive = 0;
  char __Char = getchar();
  tp __Value;
  for (; __Char < 48 || __Char > 57; __Char = getchar()) {
    __Negitive = __Char == 45;
  }
  __Value = __Char & 15;
  for (__Char = getchar(); __Char > 47 && __Char < 58; __Char = getchar()) {
    __Value = __Value * 10 + (__Char & 15);
  }
  return __Negitive ? ~__Value + 1 : __Value;
}