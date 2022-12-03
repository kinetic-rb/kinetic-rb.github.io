#include <cstdint>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 3e3 + 3, Hat_M = 1.2e4 + 3;

struct CE {
  tp to, w, next;
  CE() = default;
  CE(tp _to, tp _w, tp _next) : to(_to), w(_w), next(_next) {}
} e[Hat_M];

struct TLE {
  tp dist, pos;
  TLE() = default;
  TLE(tp _dist, tp _pos) : dist(_dist), pos(_pos) {}
  bool operator<(const TLE& comp) const { return comp.dist < dist; }
};

bool vis[Hat_N];
tp head[Hat_N], dist[Hat_N], h[Hat_N], cnt[Hat_N];
tp n;

void add_edge(tp u, tp v, tp dist) {
  static tp tot = 0;
  e[++tot] = CE(v, dist, head[u]);
  head[u] = tot;
}

void spfa(tp s) {
  queue<tp> q;
  memset(h, 0x3f, sizeof h);
  h[s] = 0;
  vis[s] = 1;
  for (q.push(s); q.size(); q.pop()) {
    vis[q.front()] = 0;
    for (tp i = head[q.front()]; i; i = e[i].next) {
      if (h[e[i].to] > h[q.front()] + e[i].w) {
        h[e[i].to] = h[q.front()] + e[i].w;
        if (!vis[e[i].to]) {
          vis[e[i].to] = 1;
          q.push(e[i].to);
          if (++cnt[e[i].to] > n) {
            throw "Error";
          }
        }
      }
    }
  }
}

void dijkstra(tp s) {
  priority_queue<TLE> p;
  memset(vis, 0, sizeof vis);
  memset(dist, 0x7f, sizeof dist);
  dist[s] = 0;
  for (p.emplace(0, s); p.size(); p.pop()) {
    if (vis[p.top().pos]) {
      continue;
    }
    vis[p.top().pos] = 1;
    for (tp i = head[p.top().pos]; i; i = e[i].next) {
      if (dist[e[i].to] > dist[p.top().pos] + e[i].w) {
        dist[e[i].to] = dist[p.top().pos] + e[i].w;
        if (!vis[e[i].to]) {
          p.emplace(dist[e[i].to], e[i].to);
        }
      }
    }
  }
}

signed main() {
  tp m;
  cin >> n >> m;
  for (tp u, v, dist; m--; add_edge(u, v, dist)) {
    cin >> u >> v >> dist;
  }
  for (tp i = 1; i <= n; ++i) {
    add_edge(0, i, 0);
  }
  try {
    spfa(0);
    for (tp i = 1; i <= n; ++i) {
      for (tp j = head[i]; j; j = e[j].next) {
        e[j].w += h[i] - h[e[j].to];
      }
    }
    for (tp i = 1; i <= n; ++i) {
      tp tar = 0;
      dijkstra(i);
      for (tp j = 1; j <= n; ++j) {
        if (dist[j] == 0x7f7f7f7f7f7f7f7f) {
          tar += j * 1e9;
        } else {
          tar += j * (dist[j] + h[j] - h[i]);
        }
      }
      cout << tar << '\n';
    }
  } catch (...) {
    puts("-1");
  }
  return 0;
}