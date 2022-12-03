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
  return __target.fill(__Val), __target;
}

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////
constexpr tp Hat_N = 1e5 + 3, Hat_K = 2e5 + 3;

struct Item {
  tp a, b, c, id;

  bool operator<(const Item& comp) const {
    if (a != comp.a) {
      return a < comp.a;
    } else if (b != comp.b) {
      return b < comp.b;
    }
    return c < comp.c;
  }
};

tp k;

array<Item, Hat_N> ca, tmp;
array<tp, Hat_N> ans, tar, s;
array<tp, Hat_K> c;

void update(tp x, tp delta) {
  while (x <= k) {
    c[x] += delta;
    x += x & -x;
  }
}

tp query(tp ind) {
  tp tot = 0;
  while (ind) {
    tot += c[ind];
    ind &= ind - 1;
  }
  return tot;
}

void CDQ(tp l, tp r) {
  if (l != r) {
    tp mid = l + r >> 1, i = l, j = mid + 1, now = l;
    CDQ(l, mid);
    CDQ(mid + 1, r);
    while (i <= mid && j <= r) {
      if (ca[i].b <= ca[j].b) {
        update(ca[i].c, s[ca[i].id]);
        tmp[now++] = ca[i++];
      } else {
        ans[ca[j].id] += query(ca[j].c);
        tmp[now++] = ca[j++];
      }
    }
    while (j <= r) {
      ans[ca[j].id] += query(ca[j].c);
      tmp[now++] = ca[j++];
    }
    for (tp k = l; k < i; ++k) {
      update(ca[k].c, -s[ca[k].id]);
    }
    while (i <= mid) {
      tmp[now++] = ca[i++];
    }
    memcpy(&ca[l], &tmp[l], (r - l + 1) * sizeof(decltype(ca)::value_type));
  }
}

signed main() {
  tp n = ra, t = 0;
  k = ra;
  for (tp i = 1; i <= n; ++i) {
    ca[i].a = ra;
    ca[i].b = ra;
    ca[i].c = ra;
  }
  stable_sort(&ca[1], &ca[n] + 1);
  for (tp i = 1; i <= n; ++i) {
    if (ca[i].a != ca[i - 1].a || ca[i].b != ca[i - 1].b ||
        ca[i].c != ca[i - 1].c) {
      ca[++t] = ca[i];
    }
    s[t]++;
  }
  for (tp i = 1; i <= t; ++i) {
    ca[i].id = i;
  }
  CDQ(1, t);
  for (tp i = 1; i <= t; ++i) {
    tar[ans[ca[i].id] + s[ca[i].id]] += s[ca[i].id];
  }
  for (tp i = 1; i <= n; ++i) {
    printf("%lld
", tar[i]);
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////