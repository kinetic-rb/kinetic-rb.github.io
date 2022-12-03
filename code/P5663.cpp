#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct CE {
  int v, next;
} edge[200002];

int odd[100001], even[100001], head[100001];
int cnt = 1;

inline void add_edge(const int& u, const int& v) {
  edge[cnt].v = v;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}

struct WA {
  int u, d;
  WA(int u, int d) : u(u), d(d) {}
};

inline void bfs() {
  queue<WA> q;
  for (q.push(WA(1, 0)); !q.empty(); q.pop())
    for (int e = head[q.front().u]; e; e = edge[e].next) {
      if (q.front().d & 1 && even[edge[e].v] > q.front().d + 1) {
        even[edge[e].v] = q.front().d + 1;
        q.push(WA(edge[e].v, q.front().d + 1));
      } else if (!(q.front().d & 1) && odd[edge[e].v] > q.front().d + 1) {
        odd[edge[e].v] = q.front().d + 1;
        q.push(WA(edge[e].v, q.front().d + 1));
      }
    }
}

int main() {
  memset(even, 0x7f, sizeof even);
  memset(odd, 0x7f, sizeof odd);
  int n, m, q;
  cin >> n >> m >> q;
  for (int u, v; m--; add_edge(u, v), add_edge(v, u))
    cin >> u >> v;
  bfs();
  for (int a, l; q--; l & 1 ? puts(odd[a] <= l ? "Yes" : "No")
                            : puts(even[a] <= l ? "Yes" : "No"))
    cin >> a >> l;
  return 0;
}