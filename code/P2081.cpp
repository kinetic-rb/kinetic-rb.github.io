#include <cstdio>
const int maxn = 100005;
int n, m, fa[maxn], son[maxn];
double up[maxn], down[maxn], ans;
struct Edge {
  int to, next, w;
  Edge() {}
  Edge(int to, int next, int w): to(to), next(next), w(w) {}
} e[maxn<<1];
int head[maxn], cnt;
void add(int u, int v, int w) {
  e[++cnt] = Edge(v, head[u], w);
  head[u] = cnt;
}
#define v e[i].to
int pos;
bool vis[maxn], flag;//\u662f\u5426\u5728\u73af\u4e0a
void dfs1(int u, int k) {
  vis[u] = true;
  for(int i = head[u]; i; i = e[i].next)
    if(v != k) {
      if(vis[v]) { pos = v; return; }
      dfs1(v, u);
      if(!flag and pos) { if(pos == u) flag = true; return; }
      if(flag) break;
    }
  vis[u] = false;
}//\u5c06\u6240\u6709\u73af\u4e0a\u7ed3\u70b9\u7684 vis \u6807\u8bb0\u4e3a true
int t, disl[22], disr[22], dfn[maxn], path[22];
void dfs2(int u, int k) {
  dfn[u] = ++t, path[t] = u;
  fa[u] = 2;
  for(int i = head[u]; i; i = e[i].next)
    if(v != k and vis[v]) {
      if(!dfn[v]) dfs2(v, u);
      disr[dfn[u]] = disl[dfn[v]] = e[i].w;
      break;
    }
}//\u5904\u7406\u73af\u4e0a\u4fe1\u606f
void dp_down(int u, int k) {
  for(int i = head[u]; i; i = e[i].next)
    if(v != k and !vis[v]) {
      fa[v] = 1;
      dp_down(v, u);
      son[u]++;
      down[u] += down[v] + e[i].w;
    }
  if(son[u]) down[u] /= son[u];
}
void dp_up(int u, int k, int w) {
  up[u] = w;
  if(fa[k] + son[k] - 1)
    up[u] += (up[k]*fa[k]+down[k]*son[k]-down[u]-w) / (fa[k]+son[k]-1);
  for(int i = head[u]; i; i = e[i].next)
    if(v != k) dp_up(v, u, e[i].w);
}
void work1() {
  dp_down(1, 0);
  for(int i = head[1]; i; i = e[i].next)
    dp_up(v, 1, e[i].w);
}
double P;
#define nxt(x) (x==t?1:x+1)
#define pre(x) (x==1?t:x-1)
void work2() {
  dfs1(1, 0);
  dfs2(pos, 0);
  for(int i = 1; i <= t; ++i)
    dp_down(path[i], 0);
  for(int i = 1, x; i <= t; ++i) {
    x = path[i];
    P = 0.5;
    for(int j = nxt(i), y; j != i; j = nxt(j)) {
      y = path[j];
      if(nxt(j) == i) up[x] += P * (disl[j]+down[y]);
      else up[x] += P * (down[y]*son[y]/(son[y]+1)+disl[j]);
      P /= (son[y]+1);
    }
    P = 0.5;
    for(int j = pre(i), y; j != i; j = pre(j)) {
      y = path[j];
      if(pre(j) == i) up[x] += P * (disr[j]+down[y]);
      else up[x] += P * (down[y]*son[y]/(son[y]+1)+disr[j]);
      P /= (son[y]+1);
    }
    for(int j = head[x]; j; j = e[j].next)
      if(!vis[e[j].to]) dp_up(e[j].to, x, e[j].w);
  }
}
#undef v
int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1, u, v, w; i <= m; ++i)
    scanf("%d %d %d", &u, &v, &w), add(u, v, w), add(v, u, w);
  if(n != m) work1();//\u666e\u901a\u6811
  else work2();//\u57fa\u73af\u6811
  for(int i = 1; i <= n; ++i)
    ans += (down[i]*son[i]+up[i]*fa[i]) / (son[i]+fa[i]);
  printf("%.5lf
", ans / n);
}