#include <stdio.h>
#define int unsigned

int mapp[70000][20];

signed main() {
  int n, num = 2;
  mapp[1][1] = 0;
  mapp[2][1] = 1;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    num <<= 1;
    for (int j = 1; j <= (num >> 1); j++) {
      for (int k = 1; k < i; k++)
        mapp[(num >> 1) + j][k] = mapp[(num >> 1) - j + 1][k];
    }
    for (int j = 1; j <= num; j++)
      mapp[j][i] = (j > (num >> 1));
  }
  for (int i = 1; i <= num; i++) {
    for (int j = 1; j <= n; j++)
      putchar(mapp[i][j] ? 'X' : 'O');
    putchar('\n');
  }
  for (int i = 0; i < n; i++)
    putchar('O');
  return 0;
}