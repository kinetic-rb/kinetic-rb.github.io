#include <algorithm>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp MAXN = 4e7 + 3, MOD = 114514'1;

tp op(tp a, tp b) {
  return (a + b >= MOD) ? (a + b - MOD) : (a + b);
}

tp f[MAXN], Sz[MAXN], w[MAXN];

void set(tp a) {
  if (f[a] != f[f[a]]) {
    set(f[a]);
    w[a] = op(w[a], w[f[a]]);
    f[a] = f[f[a]];
  }
}

void Merge(tp a, tp b) {
  set(a);
  set(b);
  a = f[a];
  b = f[b];
  if (a != b) {
    if (Sz[a] > Sz[b]) {
      swap(a, b);
    }
    f[a] = b;
    Sz[b] += Sz[a];
    w[a] = op(w[a], MOD - w[b]);
  }
}

tp Ask(tp a) {
  set(a);
  return op(w[a], (f[a] != a) * w[f[a]]);
}

void Add(tp a, tp v) {
  set(a);
  a = f[a];
  w[a] = op(w[a], v);
}

signed main() {
  tp n, m;
  scanf("%lld%lld", &n, &m);
  for (tp i = 1; i <= n; ++i) {
    scanf("%lld", &w[i]);
    w[i] %= MOD;
    f[i] = i;
    Sz[i] = 1;
  }
  for (tp i = 1, t, a, b; i <= m; ++i) {
    scanf("%lld%lld", &t, &a);
    if (t == 3) {
      printf("%lld
", Ask(a));
    }
    if (t == 2) {
      scanf("%lld", &b);
      Merge(a, b);
    }
    if (t == 1) {
      scanf("%lld", &b);
      b %= MOD;
      Add(a, b);
    }
  }
  return 0;
}