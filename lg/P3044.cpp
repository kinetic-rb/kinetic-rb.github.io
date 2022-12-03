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

constexpr tp Hat_N = 1e4 + 3;

struct Item {
  tp first, second;

  Item() = default;
  Item(tp _first, tp _second) : first(_first), second(_second) {}
};

tp n;
array<tp, Hat_N> vis;
array<vector<Item>, Hat_N> e;

void dijkstra(tp s, array<tp, Hat_N>& dist) {
  priority_queue<pair<tp, tp>, vector<pair<tp, tp>>, greater<pair<tp, tp>>> pq;
  dist.fill(-1u >> 3);
  dist[s] = 0;
  for (pq.emplace(0, s); pq.size();) {
    tp loc = pq.top().second;
    pq.pop();
    if (vis[loc] != s) {
      vis[loc] = s;
      for (auto&& i : e[loc]) {
        if (dist[i.first] > dist[loc] + i.second) {
          dist[i.first] = dist[loc] + i.second;
          if (vis[i.first] != s) {
            pq.emplace(dist[i.first], i.first);
          }
        }
      }
    }
  }
}

void __Cored__([[maybe_unused]] tp __TID__) {
  n = ra;
  tp m = ra, k = ra, MIN = -1u >> 3;
  vector<tp> core(k), lst, _p = {0, 1, 2, 3, 4};
  vector<array<tp, Hat_N>> cd(k);
  lst.reserve(n - k);
  _p.resize(k);
  for (auto&& i : core) {
    i = ra;
  }
  while (m--) {
    tp u = ra, v = ra, w = ra;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  for (tp i = 0; i < k; ++i) {
    dijkstra(core[i], cd[i]);
  }
  for (tp i = 1; i <= n; ++i) {
    bool f = 1;
    for (auto&& j : core) {
      if (i == j) {
        f = 0;
        break;
      }
    }
    if (f) {
      lst.push_back(i);
    }
  }
  for (auto&& i : lst) {
    vector<tp> p = _p;
    do {
      tp now = i, sum = 0;
      for (auto&& i : p) {
        sum += cd[i][now];
        now = core[i];
      }
      if (sum + cd[p.back()][i] < MIN) {
        MIN = sum + cd[p.back()][i];
      }
    } while (next_permutation(p.begin(), p.end()));
  }
  printf("%d
", MIN);
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}