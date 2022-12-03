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

constexpr tp MOD = 2012;

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n, l = 0;
  string s;
  cin >> s;
  n = s.size();
  vector f(n + 1, vector<tp>(n + 1, 0)), g(f);
  f[0][0] = 1;
  s = '#' + s;
  for (tp i = 1; i <= n; ++i) {
    if (s[i] == '(') {
      ++l;
      for (tp j = 0; j <= l; ++j) {
        if (j) {
          g[j][l - j] = (g[j][l - j] + f[j - 1][l - j]) % MOD;
        }
        if (l - j) {
          g[j][l - j] = (g[j][l - j] + f[j][l - j - 1]) % MOD;
        }
      }
    } else {
      --l;
      for (tp j = 0; j <= l; ++j) {
        g[j][l - j] = (g[j][l - j] + f[j + 1][l - j]) % MOD;
        g[j][l - j] = (g[j][l - j] + f[j][l - j + 1]) % MOD;
      }
    }
    for (tp j = 0; j <= l; ++j) {
      f[j][l - j] = exchange(g[j][l - j], 0);
    }
  }
  printf("%lld
", f[0][0]);
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}