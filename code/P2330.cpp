#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 5003, Hat_M = 2e5 + 3;

struct EDGE {
  tp u, v, w;

  EDGE() = default;
  EDGE(tp _u, tp _v, tp _w) : u(_u), v(_v), w(_w) {}

  bool operator<(const EDGE& comp) const { return w < comp.w; }
} e[Hat_M];

tp f[Hat_N];

void init(tp n) {
  for (tp i = 1; i <= n; ++i) {
    f[i] = i;
  }
}

tp find(tp x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(tp u, tp v) {
  f[find(u)] = find(v);
}

signed main() {
  tp n, m, tar = -(-1ull >> 2), cnt = -1;
  cin >> n >> m;
  init(n);
  for (tp i = 0; i < m; ++i) {
    tp u, v, w;
    cin >> u >> v >> w;
    e[i] = EDGE(u, v, w);
  }
  stable_sort(e, e + m);
  for (tp i = 0; i < m && cnt != n; ++i) {
    if (find(e[i].u) != find(e[i].v)) {
      tar = max(tar, e[i].w);
      merge(e[i].u, e[i].v);
      ++cnt;
    }
  }
  cout << n - 1 << ' ' << tar;
  return 0;
}