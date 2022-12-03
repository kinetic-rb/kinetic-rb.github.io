#include <iostream>

using namespace std;

long b[2005], s[2005];

long find(const long& u) {
  return (b[u] == u ? u : b[u] = find(b[u]));
}

void merge(long u, long v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  s[b[v] = u] += s[v];
}

struct CE {
  long u, v;
  CE() {}
  CE(long u, long v) : u(u), v(v) {}
  void operator[](CE x) {
    if (x.u == u)
      merge(x.v, v);
    else if (x.u == v)
      merge(x.v, u);
    else if (x.v == u)
      merge(x.u, v);
    else if (x.v == v)
      merge(x.u, u);
  }
} E[5005];

signed main() {
  long n, m, ent = 0, cnt = 0;
  cin >> n >> m;
  for (long i = 1; i <= n; i++)
    s[b[i] = i] = 1;
  for (long i = 0; i < m; i++) {
    char g;
    long u, v;
    cin >> g >> u >> v;
    if (g == 'F')
      merge(u, v);
    else
      E[ent++] = CE(u, v);
  }
  for (long i = 0; i < ent; i++)
    for (long j = i + 1; j < ent; j++)
      E[i][E[j]];
  for (long i = 1; i <= n; i++)
    if (find(i) == i)
      cnt++;
  cout << cnt;
  return 0;
}