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
  tp n = ra, k, tar;
  vector<tp> a(n + 1, 0);
  vector<list<tp>> e(n + 1);
  for_each(1 + se(a) - 1, [&tar](tp& x) { x = ra; });
  tar = ra;
  k = ra;
  while (k--) {
    tp t = ra, p = ra;
    while (p--) {
      e[t].push_front(ra);
    }
  }
  function<bool(tp)> dfs = [&](tp x) -> bool {
    if (a[x] > 0) {
      return 1;
    } else if (e[x].empty()) {
      return 0;
    }
    for (auto&& i : e[x]) {
      if (!dfs(i)) {
        return 0;
      }
    }
    for (auto&& i : e[x]) {
      --a[i];
    }
    ++a[x];
    return 1;
  };
  while (dfs(n)) {
    ++tar;
    --a[n];
  }
  printf("%lld
", tar);
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}