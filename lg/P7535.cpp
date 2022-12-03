// Please submit with C++14!
#pragma region HEAD   // Spectre
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
#define ra (scanf("%lld", &__TEMP_READ_VALUE), __TEMP_READ_VALUE)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fill(__Val), __target;
}

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////
constexpr tp Hat_N = 1e5 + 3;

signed main() {
  tp n = ra;
  array<tp, Hat_N> a;
  array<tp, Hat_N * 2> f, g;
  f.fill(-(-1ull >> 2));
  f[0] = 0;
  for (tp i = 1; i <= n; ++i) {
    a[i] = ra;
  }
  for (tp i = 1; i <= n; ++i) {
    g = f;
    for (tp j = 0; j < Hat_N; ++j) {
      f[j] = max({g[j], g[j + a[i]] + a[i], g[abs(j - a[i])] + a[i]});
    }
  }
  printf("%lld
", accumulate(&a[1], &a[n] + 1, -f[0] / 2));
  return 0;
}

////////////////////////////////////////////////////////////////////////////////