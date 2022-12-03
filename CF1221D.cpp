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
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fill(__Val), __target;
}

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

///////////////////////////////////////////////////////////////////////////////

signed main() {
  tp t = ra;
  while (t--) {
    tp n = ra;
    vector<tp> a(n + 1), b(n + 1);
    vector<array<tp, 3>> f(n + 1);
    f[0][0] = 0;
    for (tp i = 1; i <= n; ++i) {
      a[i] = ra;
      b[i] = ra;
      f[i].fill(-1ull >> 3);
    }
    for (tp i = 1; i <= n; ++i) {
      for (tp j = 0; j < 3; ++j) {
        for (tp k = 0; k < 3; ++k) {
          if (a[i] + j != a[i - 1] + k) {
            f[i][j] = min(f[i][j], f[i - 1][k] + b[i] * j);
          }
        }
      }
    }
    printf("%lld
", *min_element(f[n].begin(), f[n].end()));
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////