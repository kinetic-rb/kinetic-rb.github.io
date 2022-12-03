// Please submit with C++14!
#pragma region HEAD   // Spectre
#include <algorithm>  // By rbtree (https://rbtree.archi)
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
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
#define ra (scanf("%lld", &__TEMP_READ_VALUE), __TEMP_READ_VALUE)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////

array<tp, 50003> a, t;

signed main() {
  tp n = ra, m = ra, last = 0;
  for (tp i = 1; i <= n; ++i) {
    a[i] = t[i] = ra;
  }
  stable_sort(t.begin() + 1, t.begin() + n + 1);
  t[0] = unique(t.begin() + 1, t.begin() + n + 1) - t.begin();
  for (tp i = 1; i <= n; ++i) {
    a[i] = lower_bound(t.begin() + 1, t.begin() + t[0], a[i]) - t.begin();
  }
  while (m--) {
    tp l = (ra + last - 1) % n + 1, r = (ra + last - 1) % n + 1, MAX = 0;
    array<tp, 50003> b;
    b.fill(0);
    if (l > r) {
      swap(l, r);
    }
    for (b[0] = -1; l <= r; ++l) {
      ++b[a[l]];
    }
    for (tp i = 1; i <= t[0]; ++i) {
      if (b[i] > b[MAX]) {
        MAX = i;
      }
    }
    printf("%lld
", last = t[MAX]);
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////