#include <cstring>
#include <iostream>

using namespace std;

long f[100000], p[100000], s[100000];

long find(const long& u) {
  return (f[u] == u ? u : f[u] = find(f[u]));
}

signed main() {
  long n, m, k, tot = 0, q, ans = 0x7fffffffffff;
  cin >> n >> m >> k;
  q = m << 1;
  for (long i = 1; i <= n; i++)
    p[f[i] = i] = 1;
  for (long i = 0; i < k; i++) {
    long u, v;
    cin >> u >> v;
    u = find(u);
    v = find(v);
    if (u != v) {
      f[u] = v;
      p[v] += p[u];
    }
  }
  for (long i = 1; i <= n; i++)
    if (f[i] == i)
      s[++tot] = p[i];
  memset(f, 0, sizeof f);
  for (long i = 1; i <= tot; i++)
    for (long j = q; j >= s[i]; j--)
      f[j] = max(f[j], f[j - s[i]] + s[i]);
  for (long i = 1; i <= q; i++)
    if (abs(f[i] - m) < abs(ans - m))
      ans = f[i];
  cout << ans % 0x7fffffffffff;
  return 0;
}