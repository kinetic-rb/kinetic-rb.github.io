#include <stdio.h>

int main() {
  int n, m, sum = 0, cnt = 1;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    sum += x;
    if (sum > m) {
      cnt++;
      sum = x;
    }
  }
  printf("%d", cnt);
  return 0;
}