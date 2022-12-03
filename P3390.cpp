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

constexpr tp MOD = 1e9 + 7;
tp n = ra;

struct Matrix : array<array<tp, 100>, 100> {
  Matrix() {
    for (auto&& i : *this) {
      for (auto&& j : i) {
        j = 0;
      }
    }
  }

  Matrix operator*=(const Matrix& __val) {
    Matrix __temp;
    for (tp i = 0; i < n; ++i) {
      for (tp j = 0; j < n; ++j) {
        for (tp k = 0; k < n; ++k) {
          __temp[i][j] = (__temp[i][j] + at(i)[k] * __val[k][j]) % MOD;
        }
      }
    }
    return *this = __temp;
  }
};

void __Cored__([[maybe_unused]] tp __TID__) {
  tp k = ra;
  Matrix tar, mul;
  for (tp i = 0; i < n; ++i) {
    tar[i][i] = 1;
    for (tp j = 0; j < n; ++j) {
      mul[i][j] = ra;
    }
  }
  while (k) {
    if (k & 1) {
      tar *= mul;
    }
    mul *= mul;
    k >>= 1;
  }
  for (tp i = 0; i < n; ++i) {
    for (tp j = 0; j < n; ++j) {
      printf("%lld ", tar[i][j]);
    }
    puts("");
  }
}

////////////////////////////////////////////////////////////////////////////////

signed main(/* >_< */) {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}