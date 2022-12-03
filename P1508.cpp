#include <stdio.h>

int n, m;
int f[205][205], num[205][205];

int max(int x, int y) {
    int tx = x, ty = y;
    return tx > ty ? tx : ty;
}

int dfs(int x, int y, int sum) {
  if (!x && y > 0 && y <= m)
    return sum;
  if (x < 1 || y < 1 || x > n || y > m)
    return 0;
  if (f[x][y])
    return f[x][y];
  return f[x][y] = max(dfs(x - 1, y - 1, sum),
                       max(dfs(x - 1, y, sum), dfs(x - 1, y + 1, sum))) +
                   num[x][y];
}

signed main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", num[i] + j);
  printf("%d",
         max(dfs(n, m >> 1, 0), max(dfs(n, (m >> 1) + 1, 0), dfs(n, (m >> 1) + 2, 0))));
  return 0;
}