// By rbtree (https://rbtree.archi) :\
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
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
#define ra __Read()

using tp = long long;
tp __Read();
using namespace std;
constexpr tp Hat_N = 50003;

struct Item {
  tp u, v, y;

  Item() = default;
  Item(tp _u, tp _v, tp _y) : u(_u), v(_v), y(_y) {}

  bool operator<(const Item& comp) const { return y < comp.y; }
};

array<tp, Hat_N << 4> rec, delay;

void pushdown(tp x) {
  if (delay[x]) {
    rec[x << 1] = rec[x << 1 | 1] = delay[x << 1] = delay[x << 1 | 1] =
        exchange(delay[x], 0);
  }
}

void modify(tp x, tp l, tp r, tp ml, tp mr) {
  if (ml <= l && r <= mr) {
    delay[x] = 1;
    rec[x] = 1;
  } else {
    tp mid = l + r >> 1;
    pushdown(x);
    if (ml <= mid) {
      modify(x << 1, l, mid, ml, mr);
    }
    if (mid < mr) {
      modify(x << 1 | 1, mid + 1, r, ml, mr);
    }
    rec[x] = min(rec[x << 1], rec[x << 1 | 1]);
  }
}

tp query(tp x, tp l, tp r, tp ml, tp mr) {
  if (ml <= l && r <= mr) {
    return rec[x];
  } else {
    tp mid = l + r >> 1, MIN = 1;
    pushdown(x);
    if (ml <= mid) {
      MIN = min(MIN, query(x << 1, l, mid, ml, mr));
    }
    if (mid < mr) {
      MIN = min(MIN, query(x << 1 | 1, mid + 1, r, ml, mr));
    }
    return MIN;
  }
}

signed main() {
  tp n = ra, m, cnt = 0;
  array<tp, Hat_N> x, r;
  array<tp, Hat_N << 1> d;
  array<Item, Hat_N << 1> c;
  for (tp i = 1; i <= n; ++i) {
    x[i] = ra;
    c[i].y = ra;
    r[i] = ra;
    d[i] = (-x[i] - 1) * r[i];
    d[i + n] = -x[i] * r[i];
  }
  stable_sort(d.begin() + 1, d.begin() + n + n + 1);
  m = unique(d.begin() + 1, d.begin() + n + n + 1) - d.begin() - 1;
  for (tp i = 1; i <= n; ++i) {
    c[i].u = lower_bound(d.begin() + 1, d.begin() + m + 1, (-x[i] - 1) * r[i]) -
                 d.begin()
             << 1;
    c[i].v =
        lower_bound(d.begin() + 1, d.begin() + m + 1, -x[i] * r[i]) - d.begin()
        << 1;
  }
  stable_sort(c.begin() + 1, c.begin() + n + 1);
  for (tp i = 1; i <= n; ++i) {
    cnt += !query(1, 1, m << 1, c[i].u, c[i].v);
    modify(1, 1, m << 1, c[i].u, c[i].v);
  }
  printf("%lld
", cnt);
  return 0;
}

tp __Read() {
  bool __Negitive = 0;
  char __Char = getchar();
  tp __Value;
  for (; __Char < 48 || __Char > 57; __Char = getchar()) {
    __Negitive = __Char == 45;
  }
  __Value = __Char & 15;
  for (__Char = getchar(); __Char > 47 && __Char < 58; __Char = getchar()) {
    __Value = __Value * 10 + (__Char & 15);
  }
  return __Negitive ? ~__Value + 1 : __Value;
}