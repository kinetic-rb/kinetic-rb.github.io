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
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fill(__Val), __target;
}

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

signed main() {
  tp n = ra, m = ra, c = ra, k = ra, cnt = 0;
  vector<vector<tp>> b(67);
  array<bool, 67> h;
  set<tp> s;
  h.fill(0);
  if (!m) {
    string s;
    __int128 t = 1;
    t <<= k;
    t -= n;
    while (t) {
      s.push_back((t % 10) ^ 48);
      t /= 10;
    }
    reverse(s.begin(), s.end());
    puts(s.c_str());
    return 0;
  }
  for (tp i = 0; i < n; ++i) {
    for (tp i = (ra, 0); i < 64; ++i) {
      h[i] |= (la >> i) & 1;
    }
  }
  while (m--) {
    tp x = ra, y = ra;
    if (b[x].push_back(y); h[x]) {
      s.insert(y);
    }
  }
  for (tp i = 0; i < k; ++i) {
    bool f = 1;
    for (auto&& j : b[i]) {
      if (!s.count(j)) {
        f = 0;
        break;
      }
    }
    cnt += f;
  }
  printf("%lld
", (1ull << cnt) - n);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////