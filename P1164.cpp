#include <iostream>

using namespace std;

long f[105][10005], v[105];
long n, cnt;

inline long dfs(long c, long k) {
    if (f[c][k])
    \treturn f[c][k];
  \tif (v[c] >= k)
      \treturn (v[c] == k);
    for (long i = c + 1; i <= n; i++)
      f[c][k] += dfs(i, k - v[c]);
    return f[c][k];
}

int main() {
  \tint m;
  \tcin >> n >> m;
    for (long i = 0; i < n; i++)
      \tcin >> v[i];
    for (long i = 0; i < n; i++)
      cnt += dfs(i, m);
  \tcout << cnt;
    return 0;
}