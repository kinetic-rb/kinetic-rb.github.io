#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10, MAXM = 1e6 + 10;
int s[MAXN], stop, dfn[MAXN], low[MAXN], scccnt, sccnum[MAXN], dfscnt, tot, he[MAXN], ne[MAXM << 1], ed[MAXM << 1], n, x, y, de[MAXN], ans, m, k, dis[MAXN], num[MAXN], sum[MAXN];

inline void add(int x, int y) {
\ted[++tot] = y;
\tne[tot] = he[x];
\the[x] = tot;
}

inline void tarjan(int now) {
\tdfn[now] = low[s[stop++] = now] = ++dfscnt;
\tfor (int i = he[now]; i; i = ne[i]) {
\t\tif (!dfn[ed[i]]) {
\t\t\ttarjan(ed[i]);
\t\t\tlow[now] = min(low[now], low[ed[i]]);
\t\t} else if (!sccnum[ed[i]]) {
\t\t\tlow[now] = min(low[now], dfn[ed[i]]);
\t\t}
\t}
\tif (dfn[now] == low[now]) {
\t\tscccnt++;
\t\tdo {
\t\t\tsccnum[s[--stop]] = scccnt;
\t\t\tsum[scccnt] = min(sum[scccnt], dis[s[stop]]);
\t\t} while (s[stop] != now);
\t}
}

int main() {
\tmemset(sum, 0x7f, sizeof(sum));
\tmemset(dis, 0x7f, sizeof(dis));
\tcin >> n >> k;
\tfor (int i = 1; i <= k; i++) {
\t\tcin >> num[i] >> dis[num[i]];
\t}
\tcin >> m;
\tfor (int i = 0; i < m; i++) {
\t\tcin >> x >> y;
\t\tadd(x, y);
\t}
\tfor (int i = 1; i <= k; i++)
\t\tif (!dfn[num[i]])
\t\t\ttarjan(num[i]);
\tfor (int i = 1; i <= n; i++)
\t\tif (!dfn[i]) {
\t\t\tcout << "NO
" << i;
\t\t\treturn 0;
\t\t}
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = he[i]; j; j = ne[j])
\t\t\tif (sccnum[i] != sccnum[ed[j]])
\t\t\t\tde[sccnum[ed[j]]]++;
\tfor (int i = 1; i <= scccnt; i++)
\t\tif (!de[i])
\t\t\tans += sum[i];
\tcout << "YES
" << ans;
\treturn 0;
}