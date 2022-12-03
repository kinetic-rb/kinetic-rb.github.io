#include <stdio.h>

int ps[500005];

int main() {
  int n, MAX = 0;
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%d", ps + i);
    ps[i] = (ps[i] + ps[i - 1]) % 7;
  }
  for (register int i = 1; i <= n; i++) {
    for (register int j = i; j <= n; j++) {
      if (!(ps[j] - ps[i - 1])) {
          register int x = j - i + 1;
          if (x > MAX)
              MAX = x;
      }
    }
  }
  printf("%d", MAX);
  return 0;
}