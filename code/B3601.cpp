#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int n, cnt;
int dist[100005], head[500005];
bool vis[100005];

struct AC {
  int next, to, dist;
  AC() {}
  AC(int x, int y, int z) : next(x) {
    to = y;
    dist = z;
  }
} edge[500005];

inline void addedge(const int& u, const int& v, const int& d) {
  edge[++cnt] = AC(head[u], v, d);
  head[u] = cnt;
}

inline void spfa(int s) {
  deque<int> q;
  for (int i = 0; i <= n; i++)
    dist[i] = 0x7fffffff;
  q.push_back(s);
  dist[s] = 0;
  for (vis[s] = true; !q.empty(); q.pop_front()) {
    vis[q.front()] = false;
    for (int i = head[q.front()]; i; i = edge[i].next) {
      int v = edge[i].to;
      if (dist[v] > dist[q.front()] + edge[i].dist) {
        dist[v] = dist[q.front()] + edge[i].dist;
        if (!vis[v]) {
          vis[v] = true;
          q.push_back(v);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int f, g, w;
    cin >> f >> g >> w;
    addedge(f, g, w);
  }
  spfa(1);
  for (int i = 1; i <= n; i++)
    cout << (dist[i] == 0x7fffffff ? -1 : dist[i]) << ' ';
  return 0;
}