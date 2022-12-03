#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int n, cnt;
int dist[100005], head[500005];
bool vis[100005];

struct AC {
\tint next, to, dist;
\tAC() {}
\tAC(int x, int y, int z) : next(x) {
\t\tto = y;
\t\tdist = z;
\t}
} edge[500005];

inline void addedge(const int& u, const int& v, const int& d) {
\tedge[++cnt] = AC(head[u], v, d);
\thead[u] = cnt;
}

inline void spfa(int s) {
\tdeque<int> q;
\tfor (int i = 0; i <= n; i++)
\t\tdist[i] = 0x7fffffff;
\tq.push_back(s);
\tdist[s] = 0;
\tfor (vis[s] = true; !q.empty(); q.pop_front()) {
\t\tvis[q.front()] = false;
\t\tfor (int i = head[q.front()]; i; i = edge[i].next) {
\t\t\tint v = edge[i].to;
\t\t\tif (dist[v] > dist[q.front()] + edge[i].dist) {
\t\t\t\tdist[v] = dist[q.front()] + edge[i].dist;
\t\t\t\tif (!vis[v]) {
\t\t\t\t\tvis[v] = true;
\t\t\t\t\tq.push_back(v);
\t\t\t\t}
\t\t\t}
\t\t}
\t}
}

int main() {
\tios_base::sync_with_stdio(false);
\tint m;
\tcin >> n >> m;
\tfor (int i = 0; i < m; i++) {
\t\tint f, g, w;
\t\tcin >> f >> g >> w;
\t\taddedge(f, g, w);
\t}
\tspfa(1);
\tfor (int i = 1; i <= n; i++)
\t\tcout << (dist[i] == 0x7fffffff ? -1 : dist[i]) << ' ';
\treturn 0;
}