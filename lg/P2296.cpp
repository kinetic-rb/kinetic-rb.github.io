#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct AC {
\tint v, next;
} edge[5000005], edge1[5000005];
bool vis[5000005], vis1[5000005];
int head[5000005], head1[5000005], dis[5000005], dis1[5000005], bj[5000005];
int n, m, s, t, cnt, cnt1;

struct cmp {
\tbool operator()(int a, int b) {
\t\treturn dis[a] > dis[b];
\t}
};

struct cmp1 {
\tbool operator()(int a, int b) {
\t\treturn dis1[a] > dis1[b];
\t}
};

priority_queue<int, vector<int>, cmp> q;
priority_queue<int, vector<int>, cmp1> q1;

inline void addedge(int u, int v) {
\tedge[++cnt].v = v;
\tedge[cnt].next = head[u];
\thead[u] = cnt;
}

inline void addedge1(int u, int v) {
\tedge1[++cnt1].v = v;
\tedge1[cnt1].next = head1[u];
\thead1[u] = cnt1;
}

inline void spfa1() {
\tmemset(dis1, 0x7f, sizeof dis1);
\tq1.push(t);
\tdis1[t] = 0;
\tfor (vis1[t] = true; !q1.empty(); q1.pop()) {
\t\tvis[q1.top()] = false;
\t\tfor (int i = head1[q1.top()]; i; i = edge1[i].next) {
\t\t\tint v = edge1[i].v;
\t\t\tif (dis1[v] > dis1[q1.top()] + 1) {
\t\t\t\tdis1[v] = dis1[q1.top()] + 1;
\t\t\t\tif (!vis1[v]) {
\t\t\t\t\tq1.push(v);
\t\t\t\t\tvis1[v] = true;
\t\t\t\t}
\t\t\t}
\t\t}
\t}
\tfor (int i = 1; i <= n; i++)
\t\tif (dis1[i] == 0x7f7f7f7f) {
\t\t\tbj[i] = 1;
\t\t\tfor (int j = head1[i]; j; j = edge1[j].next)
\t\t\t\tif (edge1[j].v != s) bj[edge1[j].v] = 1;
\t\t}
}

inline void spfa() {
\tmemset(dis, 0x7f, sizeof dis);
\tq.push(s);
\tdis[s] = 0;
\tfor (vis[s] = true; !q.empty(); q.pop()) {
\t\tvis[q.top()] = false;
\t\tfor (int i = head[q.top()]; i; i = edge[i].next) {
\t\t\tint v = edge[i].v;
\t\t\tif (bj[v] == 1)
\t\t\t\tcontinue;
\t\t\tif (dis[v] > dis[q.top()] + 1) {
\t\t\t\tdis[v] = dis[q.top()] + 1;
\t\t\t\tif (!vis[v]) {
\t\t\t\t\tq.push(v);
\t\t\t\t\tvis[v] = true;
\t\t\t\t}
\t\t\t}
\t\t}
\t}
}

int main() {
\tcin >> n >> m;
\tfor (int i = 0; i < m; i++) {
\t\tint u, v;
\t\tcin >> u >> v;
\t\taddedge(u, v);
\t\taddedge1(v, u);
\t}
\tcin >> s >> t;
\tspfa1();
\tif (bj[s] == 1) {
\t\tcout << -1;
\t\treturn 0;
\t}
\tspfa();
\tcout << dis[t];
\treturn 0;
}