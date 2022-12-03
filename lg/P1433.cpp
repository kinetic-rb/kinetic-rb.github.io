#include <math.h>
#include <stdio.h>

double MIN = 1.79769e308;
double x[16], y[16], wl[16][16];
int vis[16];
int n, cnt;

void dfs(const int& idx, const int& last, const double& sum) {
  if (idx > n) {
    MIN = sum;
    return;
  }
  cnt++;
  if (cnt > 1e7)
    return;
  for (int i = 1; i <= n; i++)
    if (!vis[i] && sum + wl[last][i] < MIN) {
      vis[i] = 1;
      dfs(idx + 1, i, sum + wl[last][i]);
      vis[i] = 0;
    }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lf %lf", x + i, y + i);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      wl[i][j] =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  dfs(1, 0, 0);
  printf("%.2f", MIN);
  return 0;
}