#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <list>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 10003, Hat_M = 1e5 + 3;

bool vis[Hat_N];
tp sccno[Hat_N], sccs[Hat_N], f[Hat_N], u[Hat_M], v[Hat_M];
list<tp> stk, g[Hat_N], fg[Hat_N];
tp n, cnt;

void dfs(tp x) {
  if (vis[x]) {
    return;
  }
  vis[x] = 1;
  for (auto&& i : g[x]) {
    dfs(i);
  }
  stk.push_back(x);
}

void mark(tp x, tp f) {
  sccno[x] = f;
  ++sccs[f];
  for (auto&& i : fg[x]) {
    if (!sccno[i]) {
      mark(i, f);
    }
  }
}

void kosaraju() {
  for (tp i = 1; i <= n; ++i) {
    dfs(i);
  }
  while (stk.size()) {
    if (!sccno[stk.back()]) {
      mark(stk.back(), ++cnt);
    }
    stk.pop_back();
  }
}

signed main() {
  tp m, tot = 0, tar;
  cin >> n >> m;
  for (tp i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    g[u[i]].push_back(v[i]);
    fg[v[i]].push_back(u[i]);
  }
  kosaraju();
  for (tp i = 1; i <= n; ++i) {
    g[i].clear();
  }
  memset(vis, 0, sizeof vis);
  for (tp i = 0; i < m; ++i) {
    if (sccno[u[i]] != sccno[v[i]]) {
      g[sccno[u[i]]].push_back(sccno[v[i]]);
      vis[sccno[u[i]]] = 1;
    }
  }
  for (tp i = 1; i <= cnt; ++i) {
    if (!vis[i]) {
      ++tot;
      tar = sccs[i];
    }
  }
  if (tot == 1) {
    cout << tar;
  } else {
    cout << 0;
  }
  return 0;
}