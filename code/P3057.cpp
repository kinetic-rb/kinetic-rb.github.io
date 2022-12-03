// Please submit with C++14! It's best to use C++17 or higher version.
#ifndef LOCAL
#pragma region HEAD  // Spectre
#endif
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
#define ra (scanf("%lld", &la), la)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fitp(__Val), __target;
}

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

constexpr tp Hat_N = 3003;

tp a, b;
array<tp, Hat_N> dist;
array<vector<pair<tp, bool>>, Hat_N> e;

void dijkstra(tp s) {
  priority_queue<pair<tp, tp>, vector<pair<tp, tp>>, greater<pair<tp, tp>>> pq;
  array<bool, Hat_N> vis;
  dist.fill(-1ull >> 2);
  vis.fill(0);
  dist[s] = 0;
  for (pq.emplace(0, s); pq.size();) {
    tp loc = pq.top().second;
    if (pq.pop(); !vis[loc]) {
      for (vis[loc] = 1; auto&& i : e[loc]) {
        if (dist[i.first] > dist[loc] + (i.second ? a : b)) {
          if (dist[i.first] = dist[loc] + (i.second ? a : b); !vis[i.first]) {
            pq.emplace(dist[i.first], i.first);
          }
        }
      }
    }
  }
}

signed main() {
  tp n = ra, MAX = -1;
  a = ra;
  b = ra;
  array<tp, Hat_N * Hat_N> d;
  for (tp i = 0; i < n * n; ++i) {
    char c;
    cin >> c;
    d[i] = c == '(';
  }
  for (tp i = 0; i < n; ++i) {
    for (tp j = 0; j < n; ++j) {
      if (i > 0) {
        e[i * n + j].emplace_back(i * n + j - n,
                                  d[i * n + j] == d[i * n + j - n]);
      }
      if (j > 0) {
        e[i * n + j].emplace_back(i * n + j - 1,
                                  d[i * n + j] == d[i * n + j - 1]);
      }
      if (i + 1 < n) {
        e[i * n + j].emplace_back(i * n + j + n,
                                  d[i * n + j] == d[i * n + j + n]);
      }
      if (j + 1 < n) {
        e[i * n + j].emplace_back(i * n + j + 1,
                                  d[i * n + j] == d[i * n + j + 1]);
      }
    }
  }
  for (tp i = 0; i < n * n; ++i) {
    dijkstra(i);
    for (tp j = 0; j < n * n; ++j) {
      MAX = max(MAX, dist[j]);
    }
  }
  printf("%lld
", MAX);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////