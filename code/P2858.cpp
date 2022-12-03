#include <stdio.h>
#define max(x, y) (x > y ? x : y)

int f[2002][2002], num[2002];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", num + i);
    f[i][i] = num[i] * n;
  }
  for (int i = 2; i <= n; i++)
    for (int l = 1; l + i - 1 <= n; l++) {
      int r = l + i - 1;
      f[l][r] = max(f[l][r - 1] + num[r] * (n - i + 1),
                    f[l + 1][r] + num[l] * (n - i + 1));
    }
  printf("%d", f[1][n]);
  return 0;
}