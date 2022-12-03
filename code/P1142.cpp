#include <stdio.h>

int x[703], y[703];

signed main() {
  int n, s;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", x + i, y + i);
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int c = 2;
      for (int k = j + 1; k <= n; ++k)
        if ((x[j] - x[i]) * (y[k] - y[i]) == (y[j] - y[i]) * (x[k] - x[i]))
          ++c;
      if (c > s)
        s = c;
    }
  printf("%d", s);
  return 0;
}