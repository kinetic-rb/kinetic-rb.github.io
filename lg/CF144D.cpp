#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <utility>

using namespace std;
using tp = intmax_t;
constexpr tp Hat_N = 200003;

bool vis[Hat_N];
tp head[Hat_N], dist[Hat_N];
struct Rs {
  tp v, next, cost;

  Rs() = default;
  Rs(tp _v, tp _next, tp _cost) : v(_v), next(_next), cost(_cost) {}
} e[Hat_N];

void ADD(tp u, tp v, tp d) {
  static tp tot = 0;
  e[++tot] = Rs(v, head[u], d);
  head[u] = tot;
}

void dijkstra(tp s) {
  struct HNode {
    tp dist, loc;

    HNode() = default;
    HNode(tp _dist, tp _loc) : dist(_dist), loc(_loc) {}
    bool operator<(const HNode& comp) const { return comp.dist < dist; }
  };
  priority_queue<HNode> h;
  memset(dist, 0x7f, sizeof dist);
  dist[s] = 0;
  for (h.emplace(0, s); h.size(); h.pop()) {
    if (vis[h.top().loc]) {
      continue;
    }
    vis[h.top().loc] = 1;
    for (tp i = head[h.top().loc]; i; i = e[i].next) {
      if (dist[e[i].v] > dist[h.top().loc] + e[i].cost) {
        dist[e[i].v] = dist[h.top().loc] + e[i].cost;
        if (!vis[e[i].v]) {
          h.emplace(dist[e[i].v], e[i].v);
        }
      }
    }
  }
}

signed main() {
  tp n, m, s, l, cnt = 0;
  cin >> n >> m >> s;
  while (m--) {
    tp u, v, d;
    cin >> u >> v >> d;
    ADD(u, v, d);
    ADD(v, u, d);
  }
  cin >> l;
  dijkstra(s);
  memset(vis, 0, sizeof vis);
  for (tp u = 1; u <= n; ++u) {
    if (dist[u] == l) {
      ++cnt;
    }
    for (tp j = head[u]; j; j = e[j].next) {
      if (l > dist[u] && l - dist[u] < e[j].cost) {
        if (dist[u] + dist[e[j].v] + e[j].cost - l > l) {
          ++cnt;
        }
        if (dist[u] + dist[e[j].v] + e[j].cost - l == l && !vis[(j + 1) >> 1]) {
          ++cnt;
          vis[(j + 1) >> 1] = 1;
        }
      }
    }
  }
  cout << cnt;
  return 0;
}