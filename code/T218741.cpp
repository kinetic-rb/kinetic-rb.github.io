#include <stdio.h>

int b[] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596};

signed main() {
  int n;
  scanf("%d", &n);
  printf("%d", b[n]);
  return 0;
}