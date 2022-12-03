#include <algorithm>  // By rbtree (https://rbtree.archi)
#include <array>      // Please submit with C++14!
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
#define ddo  //
#endif
#define ra (scanf("%lld", &__TEMP_READ_VALUE), __TEMP_READ_VALUE)

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;

////////////////////////////////////////////////////////////////////////////////

tp n, MIN = -1ull >> 2;
array<tp, 23> a, sf;

void dfs(tp idx, tp b1, tp b2, tp b3) {
  if (b1 >= MIN || b1 + sf[idx] < b2 || b2 + sf[idx] < b3) {
    return;
  }
  if (idx > n) {
    if (b1 >= b2 && b2 >= b3) {
      MIN = b1;
    }
    return;
  }
  dfs(idx + 1, b1 + a[idx], b2, b3);
  dfs(idx + 1, b1, b2 + a[idx], b3);
  dfs(idx + 1, b1, b2, b3 + a[idx]);
}

signed main() {
  n = ra;
  for (tp i = 1; i <= n; ++i) {
    a[i] = ra;
  }
  stable_sort(a.begin() + 1, a.begin() + n + 1);
  reverse(a.begin() + 1, a.begin() + n + 1);
  sf[n] = a[n];
  for (tp i = n - 1; i; --i) {
    sf[i] = sf[i + 1] + a[i];
  }
  dfs(1, 0, 0, 0);
  printf("%lld
", MIN);
  return 0;
}