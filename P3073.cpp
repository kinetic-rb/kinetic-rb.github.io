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

constexpr tp dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};

tp n, limit;

vector<vector<bool>> vis;
vector<vector<tp>> a;

tp dfs(tp x, tp y) {
  tp tar = 1;
  vis[x][y] = 0;
  for (auto&& [px, py] : dir) {
    tp dx = x + px, dy = y + py;
    if (dx > 0 && dy > 0 && dx <= n && dy <= n && vis[dx][dy] &&
        abs(a[x][y] - a[dx][dy]) <= limit) {
      tar += dfs(dx, dy);
    }
  }
  return tar;
}

bool check() {
  vis = vector(n + 1, vector<bool>(n + 1, 1));
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      if (vis[i][j] && dfs(i, j) * 2 >= n * n) {
        return 1;
      }
    }
  }
  return 0;
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp l = -1ull >> 2, r = -l;
  n = ra;
  a.resize(n + 1, vector<tp>(n + 1));
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      a[i][j] = ra;
      l = min(l, a[i][j]);
      r = max(r, a[i][j]);
    }
  }
  while (l <= r) {
    if (limit = l + r >> 1; check()) {
      r = limit - 1;
    } else {
      l = limit + 1;
    }
  }
  printf("%lld
", l);
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}