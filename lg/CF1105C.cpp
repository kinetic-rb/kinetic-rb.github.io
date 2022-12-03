// Please submit with C++14! It's best to use C++17 or higher version.
#ifndef LOCAL
#pragma region HEAD  // Spectre
#endif
#include <algorithm>  // By rbtree (https://rbtree.archi)
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
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fitp(__Val), __target;
}

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

constexpr tp Hat_N = 2e5 + 3, MOD = 1e9 + 7;

signed main() {
  tp n = ra, l = ra, r = ra;
  array<array<tp, 3>, Hat_N> f;
  for (tp i = 0; i <= n; ++i) {
    f[i].fill(0);
  }
  f[0][0] = 1;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 0; j < 3; ++j) {
      for (tp k = 0; k < 3; ++k) {
        f[i][(k + j) % 3] =
            (f[i][(k + j) % 3] +
             f[i - 1][k] * ((r + j) / 3 - (l + j - 1) / 3)) %
            MOD;
      }
    }
  }
  for (tp i = 1; i <= n; ++i) {
    dbg(f[i][0]);
    dbg(f[i][1]);
    dbg(f[i][2]);
  }
  printf("%lld
", f[n][0]);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////