#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct AC {
  int v, next;
} edge[5000005], edge1[5000005];
bool vis[5000005], vis1[5000005];
int head[5000005], head1[5000005], dis[5000005], dis1[5000005], bj[5000005];
int n, m, s, t, cnt, cnt1;

struct cmp {
  bool operator()(int a, int b) {
    return dis[a] > dis[b];
  }
};

struct cmp1 {
  bool operator()(int a, int b) {
    return dis1[a] > dis1[b];
  }
};

priority_queue<int, vector<int>, cmp> q;
priority_queue<int, vector<int>, cmp1> q1;

inline void addedge(int u, int v) {
  edge[++cnt].v = v;
  edge[cnt].next = head[u];
  head[u] = cnt;
}

inline void addedge1(int u, int v) {
  edge1[++cnt1].v = v;
  edge1[cnt1].next = head1[u];
  head1[u] = cnt1;
}

inline void spfa1() {
  memset(dis1, 0x7f, sizeof dis1);
  q1.push(t);
  dis1[t] = 0;
  for (vis1[t] = true; !q1.empty(); q1.pop()) {
    vis[q1.top()] = false;
    for (int i = head1[q1.top()]; i; i = edge1[i].next) {
      int v = edge1[i].v;
      if (dis1[v] > dis1[q1.top()] + 1) {
        dis1[v] = dis1[q1.top()] + 1;
        if (!vis1[v]) {
          q1.push(v);
          vis1[v] = true;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (dis1[i] == 0x7f7f7f7f) {
      bj[i] = 1;
      for (int j = head1[i]; j; j = edge1[j].next)
        if (edge1[j].v != s) bj[edge1[j].v] = 1;
    }
}

inline void spfa() {
  memset(dis, 0x7f, sizeof dis);
  q.push(s);
  dis[s] = 0;
  for (vis[s] = true; !q.empty(); q.pop()) {
    vis[q.top()] = false;
    for (int i = head[q.top()]; i; i = edge[i].next) {
      int v = edge[i].v;
      if (bj[v] == 1)
        continue;
      if (dis[v] > dis[q.top()] + 1) {
        dis[v] = dis[q.top()] + 1;
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    addedge(u, v);
    addedge1(v, u);
  }
  cin >> s >> t;
  spfa1();
  if (bj[s] == 1) {
    cout << -1;
    return 0;
  }
  spfa();
  cout << dis[t];
  return 0;
}