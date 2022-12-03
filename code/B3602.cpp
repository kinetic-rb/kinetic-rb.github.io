#include <iostream>
#include <queue>
#define int long

using namespace std;

struct CE {
  int to, dist, next;
  CE() {}
  CE(int to, int dist, int next) : to(to), dist(dist), next(next) {}
} e[50000005];

struct TLE {
  int dist, pos;
  TLE() {}
  TLE(int dist, int pos) : dist(dist), pos(pos) {}
  bool operator<(const TLE& comp) const {
    return dist > comp.dist;
  }
};

bool vis[1000001];
int dist[1000001], head[1000001];

void add_edge(const int& u, const int& v, const int& dist) {
  static int tot = 0;
  e[++tot] = CE(v, dist, head[u]);
  head[u] = tot;
}

void dijkstra(const int& s) {
  priority_queue<TLE> heap;
  dist[s] = 0;
  for (heap.emplace(0, s); heap.size(); heap.pop()) {
    if (vis[heap.top().pos])
      continue;
    vis[heap.top().pos] = true;
    for (int i = head[heap.top().pos]; i; i = e[i].next) {
      if (dist[e[i].to] > dist[heap.top().pos] + e[i].dist)
        dist[e[i].to] = dist[heap.top().pos] + e[i].dist;
      if (!vis[e[i].to])
        heap.emplace(dist[e[i].to], e[i].to);
    }
  }
}

signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    dist[i] = 0x7ffffffffffff;
  for (int i = 0; i < m; i++) {
    int u, v, dist;
    cin >> u >> v >> dist;
    add_edge(u, v, dist);
  }
  dijkstra(1);
  for (int i = 1; i <= n; i++)
    cout << (dist[i] == 0x7ffffffffffff ? -1 : dist[i]) << ' ';
  return 0;
}