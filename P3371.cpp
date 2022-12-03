#include "iostream"
#include "queue"

using namespace std;

struct CE {
  int to, dist, next;
  CE() {}
  CE(int to, int dist, int next) : to(to), dist(dist), next(next) {}
} e[500005];

bool vis[10001];
int dist[10001], head[10001];
int n;

void add_edge(const int& u, const int& v, const int& dist) {
  static int tot = 0;
  e[++tot] = CE(v, dist, head[u]);
  head[u] = tot;
}

void spfa(const int& s) {
  queue<int> Q;
  for (int i = 1; i <= n; i++)
    dist[i] = 0x7fffffff;
  dist[s] = 0;
  vis[s] = true;
  for (Q.push(s); Q.size(); Q.pop()) {
    vis[Q.front()] = false;
    for (int i = head[Q.front()]; i; i = e[i].next) {
      if (dist[e[i].to] > dist[Q.front()] + e[i].dist) {
        dist[e[i].to] = dist[Q.front()] + e[i].dist;
        if (!vis[e[i].to]) {
          vis[e[i].to] = true;
          Q.push(e[i].to);
        }
      }
    }
  }
}

int main() {
  int m, s;
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    int u, v, dist;
    cin >> u >> v >> dist;
    add_edge(u, v, dist);
  }
  spfa(s);
  for (int i = 1; i <= n; i++)
    cout << dist[i] << ' ';
  return 0;
}