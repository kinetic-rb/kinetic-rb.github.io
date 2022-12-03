#include <algorithm>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

struct Rs {
  tp l, r;
  
  bool operator<(const Rs& comp) const {
    return l < comp.l;
  }
} p[Hat_N];
tp n, m;

bool check(tp d) {
  tp ml = 0, loc = p->l;
  for (tp i = 0; i < n; ++i) {
    while (loc > p[ml].r) {
      if (++ml == m) {
        return 0;
      }
    }
    loc = max(loc, p[ml].l);
    loc += d;
  }
  return 1;
}

tp fs() {
  tp qloc = 0;
  for (tp loc = 1ll << 60; loc; loc >>= 1) {
    if (check(qloc + loc)) {
      qloc += loc;
    }
  }
  return qloc;
}

signed main() {
  scanf("%lld%lld", &n, &m);
  for (tp i = 0; i < m; ++i) {
    scanf("%lld%lld", &p[i].l, &p[i].r);
  }
  stable_sort(p, p + m);
  printf("%lld
", fs());
  return 0;
}