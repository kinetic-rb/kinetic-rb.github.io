#include <cstring>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 200003;

vector<list<tp>> g;
bool vis[Hat_N];
tp res[Hat_N];
tp now;

void dfs(tp x) {
  if (vis[x]) {
    return;
  }
  res[x] = now;
  vis[x] = 1;
  for (auto&& i : g[x]) {
    dfs(i);
  }
}

signed main() {
  tp n, m, s;
  cin >> n >> m;
  g.resize(n + 1);
  while (m--) {
    tp u, v;
    cin >> u >> v;
    g[v].push_back(u);
  }
  for (tp i = n; i; --i) {
    now = i;
    dfs(i);
  }
  for (tp i = 1; i <= n; ++i) {
    cout << res[i] << ' ';
  }
  return 0;
}