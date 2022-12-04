// By rbtree (https://rbtree.asia) :\
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
constexpr tp Hat_N = 1e5 + 3, Mod = 1e6 + 7;

signed main() {
  tp n = ra, m = ra;
  array<tp, Hat_N> a, f, ps;
  for (tp i = 1; i <= n; ++i) {
    a[i] = ra;
  }
  f.fill(0);
  ps.fill(1);
  f[0] = 1;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 0; j <= m; ++j) {
      f[j] = ps[j] - (j > a[i] ? ps[j - a[i] - 1] : 0);
      f[j] = (f[j] + Mod) % Mod;
    }
    ps[0] = f[0];
    for (tp j = 1; j <= m; ++j) {
      ps[j] = (ps[j - 1] + f[j]) % Mod;
    }
  }
  printf("%lld
", f[m]);
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