// By rbtree (https://rbtree.asia) :\
// Please submit with C++14!
#include <algorithm>
#include <array>
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
constexpr tp Hat_N = 5e5 + 3;

array<tp, Hat_N> hson, dep, top, fa, s;
array<vector<tp>, Hat_N> tr;

void dfs1(tp x) {
  tp temp = -1;
  dep[x] = dep[fa[x]] + 1;
  s[x] = 1;
  for (auto&& i : tr[x]) {
    if (i != fa[x]) {
      fa[i] = x;
      dfs1(i);
      s[x] += s[i];
      if (temp < s[i]) {
        hson[x] = i;
        temp = s[i];
      }
    }
  }
}

void dfs2(tp x, tp h) {
  top[x] = h;
  if (hson[x]) {
    dfs2(hson[x], h);
  }
  for (auto&& i : tr[x]) {
    if (i != fa[x] && i != hson[x]) {
      dfs2(i, i);
    }
  }
}

tp LCA(tp x, tp y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] > dep[top[y]]) {
      x = fa[top[x]];
    } else {
      y = fa[top[y]];
    }
  }
  return dep[x] < dep[y] ? x : y;
}

signed main() {
  tp n = ra, m = ra;
  for (tp i = 1; i < n; ++i) {
    tp u = ra, v = ra;
    tr[u].push_back(v);
    tr[v].push_back(u);
  }
  dfs1(1);
  dfs2(1, 1);
  while (m--) {
    tp a = ra, b = ra, c = ra, d = ra, e = LCA(a, b), f = LCA(c, d);
    if (dep[e] < dep[f]) {
      swap(e, f);
      swap(a, c);
      swap(b, d);
    }
    puts(LCA(e, c) == e || LCA(e, d) == e ? "Y" : "N");
  }
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