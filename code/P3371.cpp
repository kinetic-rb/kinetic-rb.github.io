// Please submit with C++14! It's best to use C++20 or higher version.
constexpr bool __MTCS__ = 0;  // Spectre
#ifndef LOCAL                 // By rbtree (https://rbtree.dev)
#pragma region HEAD
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
using namespace std;
void __Cored__(tp);
tp la;

signed main(/* >_< */) {
  for (static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0; __NOW__ < __TCS__;
       __Cored__(++__NOW__)) {
  }
  return 0;
}

#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

constexpr tp Hat_N = 1e5 + 3;

bool inq[Hat_N];
tp dist[Hat_N];
vector<pair<tp, tp>> e[Hat_N];

void spfa(tp s) {
  list<tp> q;
  memset(inq, 0, sizeof inq);
  fill(dist, dist + Hat_N, (1ll << 31) - 1);
  inq[s] = 1;
  dist[s] = 0;
  for (q.push_back(s); q.size(); q.pop_front()) {
    inq[q.front()] = 0;
    for (auto&& [i, j] : e[q.front()]) {
      if (dist[i] > dist[q.front()] + j) {
        dist[i] = dist[q.front()] + j;
        if (!inq[i]) {
          inq[i] = 1;
          q.push_back(i);
        }
      }
    }
  }
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, m = ra, s = ra;
  while (m--) {
    tp u = ra, v = ra, w = ra;
    e[u].emplace_back(v, w);
  }
  spfa(s);
  for (tp i = 1; i <= n; ++i) {
    printf("%lld ", dist[i]);
  }
}