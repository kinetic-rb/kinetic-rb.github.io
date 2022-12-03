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

constexpr tp Hat_N = 1e5 + 3;

bool vis[Hat_N];
tp dist[Hat_N];
vector<pair<tp, tp>> e[Hat_N];

void dijkstra(tp s) {
  priority_queue<pair<tp, tp>, vector<pair<tp, tp>>, greater<pair<tp, tp>>> q;
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  dist[s] = 0;
  for (q.emplace(0, s); q.size();) {
    tp l = q.top().second;
    if (q.pop(); !vis[l]) {
      vis[l] = 1;
      for (auto&& [i, j] : e[l]) {
        if (dist[i] > dist[l] + j) {
          if (dist[i] = dist[l] + j; !vis[i]) {
            q.emplace(dist[i], i);
          }
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
  dijkstra(s);
  for (tp i = 1; i <= n; ++i) {
    printf("%lld ", dist[i]);
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