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
  tp n = ra, m = ra;
  vector<set<tp>> v({{1}});
  vector<vector<tp>> e(n + 1);
  for (tp i = 1; i <= m; ++i) {
    tp t = ra;
    v.emplace_back();
    while (t--) {
      e[ra].push_back(i);
      v.back().insert(la);
    }
  }
  for (list<tp> q({1}); q.size(); q.pop_front()) {
    for (auto&& i : e[q.front()]) {
      if (v[i].erase(q.front()); v[i].size() == 1) {
        v.front().insert(*v[i].begin());
        q.push_back(*v[i].begin());
      }
    }
  }
  printf("%zu", v.front().size());
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}