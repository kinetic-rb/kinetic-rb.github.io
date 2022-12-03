#include <cstring>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 200003;

vector<list<tp>> g;
bool vis[Hat_N];

void dfs(tp x) {
  if (vis[x]) {
    return;
  }
  vis[x] = 1;
  cout << x << ' ';
  for (auto&& i : g[x]) {
    dfs(i);
  }
}

void bfs(tp s) {
  list<tp> q;
  vis[s] = 1;
  for (q.push_back(s); q.size(); q.pop_front()) {
    cout << q.front() << ' ';
    for (auto&& i : g[q.front()]) {
      if (!vis[i]) {
        vis[i] = 1;
        q.push_back(i);
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n, m, s;
  cin >> n >> m >> s;
  g.resize(n + 1);
  while (m--) {
    tp u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(s);
  memset(vis, 0, sizeof vis);
  cout << '\n';
  bfs(s);
  return 0;
}