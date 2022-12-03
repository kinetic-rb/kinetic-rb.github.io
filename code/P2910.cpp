#include <stdio.h>

int dis[101][101], num[10001];

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  m++;
  n++;
  for (register int i = 1; i < m; i++)
    scanf("%d", num + i);
  for (register int i = 1; i < n; i++)
    for (register int j = 1; j < n; j++)
      scanf("%d", &dis[i][j]);
  for (register int k = 1; k < n; k++)
    for (register int i = 1; i < n; i++)
      for (register int j = 1; j < n; j++)
        if (dis[i][k] + dis[k][j] < dis[i][j])
          dis[i][j] = dis[i][k] + dis[k][j];
  for (register int i = 2; i < m; i++)
    ans += dis[num[i - 1]][num[i]];
  printf("%d", ans);
  return 0;
}