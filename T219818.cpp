#include <iostream>

using namespace std;
using tp = int;
constexpr tp Hat_N = 100003;

struct Edge {
  tp y, l, to;
  
  Edge() = default;
  Edge(tp y, tp l, tp to) : y(y), l(l), to(to) {}
} e[Hat_N << 1];

struct Rs {
  tp et;
  tp l[2];
} v[Hat_N];

tp n, MAX;

void add(tp i, tp x, tp y, tp z) {
  e[i] = Edge(y, z, v[x].et);
  v[x].et = i;
}

void dfs(tp f, tp x) {
  for (tp i = v[x].et; i; i = e[i].to) {
    if (e[i].y != f) {
      dfs(x, e[i].y);
      if (tp l = v[e[i].y].l[0] + e[i].l; l >= v[x].l[0]) {
        v[x].l[1] = v[x].l[0];
        v[x].l[0] = l;
      } else if (l > v[x].l[1]) {
        v[x].l[1] = l;
      }
    }
  }
}

void Calc(tp fl, tp f, tp x) {
  if (fl > MAX) {
    MAX = fl;
  }
  for (tp i = v[x].et; i; i = e[i].to) {
    if (e[i].y != f) {
      Calc(max(fl, v[e[i].y].l[0] + e[i].l == v[x].l[0] ?
               v[x].l[1] : v[x].l[0]) + e[i].l, x, e[i].y);
    }
  }
}

signed main() {
  cin >> n;
  for (tp i = 1; i < n; ++i) {
    tp u, v, d;
    cin >> u >> v >> d;
    add(i << 1, u, v, d);
    add(i << 1 | 1, v, u, d);
  }
  dfs(0, 1);
  Calc(0, 0, 1);
  cout << MAX;
  return 0;
}