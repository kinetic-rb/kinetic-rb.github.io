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

struct Item {
  tp x, y, a, b;

  bool operator<(const Item& comp) const {
    return make_pair(x, y) < make_pair(comp.x, comp.y);
  }
};

tp n;
vector<Item> a;

void calc() {
  stable_sort(se(a));
  for (tp i = 0, j = 0, r = 0; i < n; i = j) {
    while (j < n && a[j].x == a[i].x) {
      r += a[j++].y;
    }
    for (tp k = i, l = 0; k < j; ++k) {
      r -= a[k].y;
      a[k].a = (r - (j - k - 1) * a[k].y + a[k].y * (k - i) - l) % MOD;
      l += a[k].y;
    }
  }
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp sum = 0;
  n = ra;
  a.resize(n);
  for (auto&& [i, j, _, __] : a) {
    i = ra;
    j = ra;
  }
  calc();
  for (auto&& [i, j, x, y] : a) {
    swap(i, j);
    swap(x, y);
  }
  calc();
  for (auto&& [_, __, i, j] : a) {
    sum += i * j;
  }
  printf("%lld
", sum % MOD);
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}