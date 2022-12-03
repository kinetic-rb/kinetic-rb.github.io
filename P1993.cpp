#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 5e3 + 3, Hat_M = 2e4 + 3;

struct CE {
  tp to, w, next;
  CE() = default;
  CE(tp _to, tp _w, tp _next) : to(_to), w(_w), next(_next) {}
} e[Hat_M];

bool vis[Hat_N];
tp dist[Hat_N], head[Hat_N], cnt[Hat_N];
tp n;

void add_edge(tp u, tp v, tp dist) {
  static tp tot = 0;
  e[++tot] = CE(v, dist, head[u]);
  head[u] = tot;
}

void spfa(tp s) {
  queue<tp> Q;
  memset(dist, -1, sizeof dist);
  dist[s] = 0;
  vis[s] = 1;
  for (Q.push(s); Q.size(); Q.pop()) {
    vis[Q.front()] = 0;
    for (tp i = head[Q.front()]; i; i = e[i].next) {
      if (dist[e[i].to] < dist[Q.front()] + e[i].w) {
        dist[e[i].to] = dist[Q.front()] + e[i].w;
        if (!vis[e[i].to]) {
          vis[e[i].to] = 1;
          Q.push(e[i].to);
          if (++cnt[e[i].to] == n) {
            cout << "No";
            return;
          }
        }
      }
    }
  }
  cout << "Yes";
}

signed main() {
  tp m;
  cin >> n >> m;
  while (m--) {
    tp op, u, v;
    cin >> op >> u >> v;
    if (op == 3) {
      add_edge(u, v, 0);
      add_edge(v, u, 0);
    } else {
      tp w;
      cin >> w;
      if (op == 1) {
        add_edge(u, v, w);
      } else {
        add_edge(v, u, -w);
      }
    }
  }
  for (tp i = 1; i <= n; ++i) {
    add_edge(0, i, 0);
  }
  spfa(0);
  return 0;
}