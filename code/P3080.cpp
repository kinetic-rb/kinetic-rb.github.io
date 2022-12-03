// Please submit with C++14! It's best to use C++20 or higher version.
#ifndef LOCAL        // Spectre
#pragma region HEAD  // By rbtree (https://rbtree.dev)
#endif
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstring>
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
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#endif
#define ra (scanf("%lld", &la), la)
#define se(exp) exp.begin(), exp.end()
#define fe(arr, exp) for_each(se(arr), exp)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

constexpr bool __MTCS__ = 0;

////////////////////////////////////////////////////////////////////////////////

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra + 1, t;
  vector<tp> a(n + 1, 0);
  vector f(n + 1, vector(n + 1, vector(2, -1ull >> 2)));
  for (tp i = 1; i < n; ++i) {
    a[i] = ra;
  }
  stable_sort(a.begin() + 1, a.begin() + n + 1);
  t = lower_bound(a.begin() + 1, a.begin() + n + 1, 0) - a.begin();
  f[t][t][1] = f[t][t][0] = 0;
  for (tp _ = 2; _ <= n; ++_) {
    for (tp i = 1; i + _ - 1 <= n; ++i) {
      tp j = i + _ - 1;
      f[i][j][0] = min(f[i + 1][j][0] + (a[i + 1] - a[i]) * (i + n - j),
                       f[i + 1][j][1] + (a[j] - a[i]) * (i + n - j));
      f[i][j][1] = min(f[i][j - 1][0] + (a[j] - a[i]) * (i + n - j),
                       f[i][j - 1][1] + (a[j] - a[j - 1]) * (i + n - j));
    }
  }
  printf("%lld
", min(f[1][n][0], f[1][n][1]));
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}