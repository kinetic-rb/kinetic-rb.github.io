#include <algorithm>
#include <iostream>

using namespace std;
using tp = int;
constexpr tp MAXN = 1e7 + 3, MOD = 114514'1;

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
  scanf("%d%d", &n, &m);
  for (tp i = 1; i <= n; ++i) {
    scanf("%d", &w[i]);
    w[i] %= MOD;
    f[i] = i;
    Sz[i] = 1;
  }
  for (tp i = 1, t, a, b; i <= m; ++i) {
    scanf("%d%d", &t, &a);
    if (t == 3) {
      printf("%d
", Ask(a));
    } else if (t == 2) {
      scanf("%d", &b);
      Merge(a, b);
    } else {
      scanf("%d", &b);
      b %= MOD;
      Add(a, b);
    }
  }
  return 0;
}