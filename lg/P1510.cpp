#include "stdio.h"

int f[10001], m[10001], w[10001];

int main() {
  int v, n, c;
  scanf("%d%d%d", &v, &n, &c);
  for (register int i = 1; i <= n; i++)
    scanf("%d%d", m + i, w + i);
  for (register int i = 1; i <= n; i++)
    for (register int j = c; j >= w[i]; j--)
      if (f[j - w[i]] + m[i] > f[j])
        f[j] = f[j - w[i]] + m[i];
  for (register int i = 0; i <= v; i++)
    if (f[i] >= v) {
      printf("%d", c - i);
      return 0;
    }
  printf("Impossible");
  return 0;
}