#include <cstdio>
const int maxn = 100005;
int n, m, fa[maxn], son[maxn];
double up[maxn], down[maxn], ans;
struct Edge {
\tint to, next, w;
\tEdge() {}
\tEdge(int to, int next, int w): to(to), next(next), w(w) {}
} e[maxn<<1];
int head[maxn], cnt;
void add(int u, int v, int w) {
\te[++cnt] = Edge(v, head[u], w);
\thead[u] = cnt;
}
#define v e[i].to
int pos;
bool vis[maxn], flag;//\u662f\u5426\u5728\u73af\u4e0a
void dfs1(int u, int k) {
\tvis[u] = true;
\tfor(int i = head[u]; i; i = e[i].next)
\t\tif(v != k) {
\t\t\tif(vis[v]) { pos = v; return; }
\t\t\tdfs1(v, u);
\t\t\tif(!flag and pos) { if(pos == u) flag = true; return; }
\t\t\tif(flag) break;
\t\t}
\tvis[u] = false;
}//\u5c06\u6240\u6709\u73af\u4e0a\u7ed3\u70b9\u7684 vis \u6807\u8bb0\u4e3a true
int t, disl[22], disr[22], dfn[maxn], path[22];
void dfs2(int u, int k) {
\tdfn[u] = ++t, path[t] = u;
\tfa[u] = 2;
\tfor(int i = head[u]; i; i = e[i].next)
\t\tif(v != k and vis[v]) {
\t\t\tif(!dfn[v]) dfs2(v, u);
\t\t\tdisr[dfn[u]] = disl[dfn[v]] = e[i].w;
\t\t\tbreak;
\t\t}
}//\u5904\u7406\u73af\u4e0a\u4fe1\u606f
void dp_down(int u, int k) {
\tfor(int i = head[u]; i; i = e[i].next)
\t\tif(v != k and !vis[v]) {
\t\t\tfa[v] = 1;
\t\t\tdp_down(v, u);
\t\t\tson[u]++;
\t\t\tdown[u] += down[v] + e[i].w;
\t\t}
\tif(son[u]) down[u] /= son[u];
}
void dp_up(int u, int k, int w) {
\tup[u] = w;
\tif(fa[k] + son[k] - 1)
\t\tup[u] += (up[k]*fa[k]+down[k]*son[k]-down[u]-w) / (fa[k]+son[k]-1);
\tfor(int i = head[u]; i; i = e[i].next)
\t\tif(v != k) dp_up(v, u, e[i].w);
}
void work1() {
\tdp_down(1, 0);
\tfor(int i = head[1]; i; i = e[i].next)
\t\tdp_up(v, 1, e[i].w);
}
double P;
#define nxt(x) (x==t?1:x+1)
#define pre(x) (x==1?t:x-1)
void work2() {
\tdfs1(1, 0);
\tdfs2(pos, 0);
\tfor(int i = 1; i <= t; ++i)
\t\tdp_down(path[i], 0);
\tfor(int i = 1, x; i <= t; ++i) {
\t\tx = path[i];
\t\tP = 0.5;
\t\tfor(int j = nxt(i), y; j != i; j = nxt(j)) {
\t\t\ty = path[j];
\t\t\tif(nxt(j) == i) up[x] += P * (disl[j]+down[y]);
\t\t\telse up[x] += P * (down[y]*son[y]/(son[y]+1)+disl[j]);
\t\t\tP /= (son[y]+1);
\t\t}
\t\tP = 0.5;
\t\tfor(int j = pre(i), y; j != i; j = pre(j)) {
\t\t\ty = path[j];
\t\t\tif(pre(j) == i) up[x] += P * (disr[j]+down[y]);
\t\t\telse up[x] += P * (down[y]*son[y]/(son[y]+1)+disr[j]);
\t\t\tP /= (son[y]+1);
\t\t}
\t\tfor(int j = head[x]; j; j = e[j].next)
\t\t\tif(!vis[e[j].to]) dp_up(e[j].to, x, e[j].w);
\t}
}
#undef v
int main() {
\tscanf("%d %d", &n, &m);
\tfor(int i = 1, u, v, w; i <= m; ++i)
\t\tscanf("%d %d %d", &u, &v, &w), add(u, v, w), add(v, u, w);
\tif(n != m) work1();//\u666e\u901a\u6811
\telse work2();//\u57fa\u73af\u6811
\tfor(int i = 1; i <= n; ++i)
\t\tans += (down[i]*son[i]+up[i]*fa[i]) / (son[i]+fa[i]);
\tprintf("%.5lf
", ans / n);
}