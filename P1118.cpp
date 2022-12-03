#include <stdio.h>
#include <stdlib.h>
#define int unsigned

int n, k;
int cho[13], b[24][24] = {1};
int vis[13];

void gob(int);
inline void gob(int n) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
}

int SUM();
inline int SUM() {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += cho[i] * b[n][i + 1];
  return sum;
}

void dfs(int);
inline void dfs(int idx) {
  if (idx == n) {
    if (SUM() == k) {
      for (int i = 0; i < n; i++)
          printf("%d ", cho[i]);
      exit(0);
    }
    return;
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      vis[i] = 1;
      cho[idx] = i;
      dfs(idx + 1);
      vis[i] = 0;
    }
}

signed main() {
    scanf("%d%d", &n, &k);
  gob(n);
  dfs(0);
  return 0;
}