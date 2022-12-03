// Please submit with C++14!
#pragma region HEAD   // Spectre
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
#define ra (scanf("%lld", &__TEMP_READ_VALUE), __TEMP_READ_VALUE)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fitp(__Val), __target;
}

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////
constexpr tp Hat_N = 50003;

tp sum;
array<tp, Hat_N> a, b, cnt;

struct Item {
  tp l, r, id;

  bool operator<(const Item& comp) const {
    if (b[l] != b[comp.l]) {
      return b[l] < b[comp.l];
    }
    return r < comp.r;
  }
};

array<pair<tp, tp>, Hat_N> tar;
array<Item, Hat_N> s;

void modify(tp x, tp d) {
  sum -= cnt[a[x]] * cnt[a[x]];
  cnt[a[x]] += d;
  sum += cnt[a[x]] * cnt[a[x]];
}

signed main() {
  tp n = ra, q = ra, bk = sqrt(n), ql = 1, qr = 0;
  cnt.fill(0);
  for (tp i = 1; i <= n; ++i) {
    a[i] = ra;
    b[i] = (i + bk - 1) / bk;
  }
  for (tp i = 0; i < q; ++i) {
    s[i].l = ra;
    s[i].r = ra;
    s[i].id = i;
  }
  stable_sort(&s[0], &s[q]);
  for (tp i = 0; i < q; ++i) {
    for (; qr < s[i].r; modify(++qr, 1)) {
    }
    for (; qr > s[i].r; modify(qr--, -1)) {
    }
    for (; ql < s[i].l; modify(ql++, -1)) {
    }
    for (; ql > s[i].l; modify(--ql, 1)) {
    }
    tar[s[i].id].first = sum - (s[i].r - s[i].l + 1);
    tar[s[i].id].second = (s[i].r - s[i].l + 1) * (s[i].r - s[i].l);
  }
  for (tp i = 0; i < q; ++i) {
    tp g = __gcd(tar[i].first, tar[i].second);
    if (g) {
      printf("%lld/%lld
", tar[i].first / g, tar[i].second / g);
    } else {
      puts("0/1");
    }
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////