#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10, MAXM = 1e6 + 10;
int s[MAXN], stop, dfn[MAXN], low[MAXN], scccnt, sccnum[MAXN], dfscnt, tot, he[MAXN], ne[MAXM << 1], ed[MAXM << 1], n, x, y, de[MAXN], ans, m, k, dis[MAXN], num[MAXN], sum[MAXN];

inline void add(int x, int y) {
  ed[++tot] = y;
  ne[tot] = he[x];
  he[x] = tot;
}

inline void tarjan(int now) {
  dfn[now] = low[s[stop++] = now] = ++dfscnt;
  for (int i = he[now]; i; i = ne[i]) {
    if (!dfn[ed[i]]) {
      tarjan(ed[i]);
      low[now] = min(low[now], low[ed[i]]);
    } else if (!sccnum[ed[i]]) {
      low[now] = min(low[now], dfn[ed[i]]);
    }
  }
  if (dfn[now] == low[now]) {
    scccnt++;
    do {
      sccnum[s[--stop]] = scccnt;
      sum[scccnt] = min(sum[scccnt], dis[s[stop]]);
    } while (s[stop] != now);
  }
}

int main() {
  memset(sum, 0x7f, sizeof(sum));
  memset(dis, 0x7f, sizeof(dis));
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> num[i] >> dis[num[i]];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    add(x, y);
  }
  for (int i = 1; i <= k; i++)
    if (!dfn[num[i]])
      tarjan(num[i]);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) {
      cout << "NO
" << i;
      return 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = he[i]; j; j = ne[j])
      if (sccnum[i] != sccnum[ed[j]])
        de[sccnum[ed[j]]]++;
  for (int i = 1; i <= scccnt; i++)
    if (!de[i])
      ans += sum[i];
  cout << "YES
" << ans;
  return 0;
}