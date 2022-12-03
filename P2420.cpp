#include <bits/stdc++.h>
using namespace std;
struct node {
  int e, f, v;
} a[200005];
int h[100005];
int tot = 0;
int sum[100005];
bool sf[100005];
void dfs(int x) {
  sf[x] = 1;
  for (int i = h[x]; i; i = a[i].f)
    if (!sf[a[i].e]) {
      sum[a[i].e] = (sum[x] ^ a[i].v);
      dfs(a[i].e);
    }
  return;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[++tot].f = h[u];
    h[u] = tot;
    a[tot].e = v;
    a[tot].v = w;
    a[++tot].f = h[v];
    h[v] = tot;
    a[tot].e = u;
    a[tot].v = w;
  }
  int s = (n < 7 ? n : 7);
  dfs(s);
  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    cout << (sum[u] ^ sum[v])<<endl;
  }
  return 0;
}