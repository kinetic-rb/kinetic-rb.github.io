#include <cstdint>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
using tp = int64_t;

struct CE {
  tp to, dist, next;
  CE() {}
  CE(tp to, tp dist, tp next) : to(to), dist(dist), next(next) {}
};

unordered_map<tp, CE> e;
bool vis[10001];
tp dist[10001], head[10001], cnt[10001];
tp n, tot;

void add_edge(tp u, tp v, tp dist) {
  e[++tot] = CE(v, dist, head[u]);
  head[u] = tot;
}

void spfa(const tp& s) {
  queue<tp> Q;
  memset(dist, 0x7f, sizeof dist);
  memset(vis, 0, sizeof vis);
  memset(cnt, 0, sizeof cnt);
  dist[s] = 0;
  vis[s] = 1;
  for (Q.push(s); Q.size(); Q.pop()) {
    vis[Q.front()] = 0;
    for (tp i = head[Q.front()]; i; i = e[i].next) {
      if (dist[e[i].to] > dist[Q.front()] + e[i].dist) {
        dist[e[i].to] = dist[Q.front()] + e[i].dist;
        if (!vis[e[i].to]) {
          vis[e[i].to] = 1;
          Q.push(e[i].to);
          if (++cnt[Q.front()] == n) {
            cout << "YES
";
            return;
          }
        }
      }
    }
  }
  cout << "NO
";
}

void Core() {
  tp m;
  tot = 0;
  memset(head, 0, sizeof head);
  e.clear();
  cin >> n >> m;
  for (tp i = 0; i < m; ++i) {
    tp u, v, w;
    cin >> u >> v >> w;
    add_edge(u, v, w);
    if (w >= 0) {
      add_edge(v, u, w);
    }
  }
  spfa(1);
}

signed main() {
  tp T;
  cin >> T;
  while (T--) {
    Core();
  }
  return 0;
}