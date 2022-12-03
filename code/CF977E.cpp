#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using i16 = short;
using i32 = int;
using i64 = long long;
using ui16 = unsigned short;
using ui32 = unsigned int;
using ui64 = unsigned long long;
using namespace std;

i64 b[200005], in[200005], out[200005];
bitset<200005> vis;  
vector<i64> G[200005], bp[200005];

void init(i64 n) {
  for (i64 i = 1; i <= n; i++)
    b[i] = i;
}

i64 find(i64 u) {
  return (b[u] == u ? u : b[u] = find(b[u]));
}

void merge(i64 u, i64 v) {
  b[find(v)] = find(u);
}

void dfs(i64 u) {
  if (vis[u])
    return;
  vis[u] = true;
  for (auto i : G[u]) {
    merge(i, u);
    dfs(i);
  }
}

bool checkH(i64 u) {
  for (auto i : bp[u])
    if (in[i] != 2 || out[i] != 2)
      return false;
  return true;
}

i32 main() {
  i64 n, m, cnt = 0;
  cin >> n >> m;
  init(n);
  for (i64 u, v; m--; G[u].push_back(v), G[v].push_back(u)) {
    cin >> u >> v;
    ++in[v];
    ++out[u];
    ++in[u];
    ++out[v];
  }
  for (i64 i = 1; i <= n; ++i)
    if (!vis[i])
      dfs(i);
  for (i64 i = 1; i <= n; ++i)
    bp[find(i)].push_back(i);
  for (i64 i = 1; i <= n; ++i)
    if (b[i] == i && checkH(i))
      ++cnt;
  printf("%lld", cnt);
  return 0;
}