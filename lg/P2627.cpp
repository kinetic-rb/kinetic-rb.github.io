#include <stdint.h>
#include <stdio.h>
#define tp int64_t
#define max(x, y) x > y ? x : y

int64_t ps[100003], f[100003];

signed main() {
  tp n, k, save;
  scanf("%ld%ld", &n, &k);
  save = n & 1;
  n -= save;
  for (tp i = 1; i <= n; i += 2) {
    scanf("%ld%ld", ps + i, ps + i + 1);
    ps[i + 1] += ps[i] += ps[i - 1];
  }
  n += save;
  if (save) {
    scanf("%ld", ps + n);
    ps[n] += ps[n - 1];
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = max(0, i - k); j <= i; ++j) {
      if (f[j - 1] + ps[i] - ps[j] > f[i]) {
        f[i] =  f[j - 1] + ps[i] - ps[j];
      }
    }
  }
  printf("%ld", f[n]);
  return 0;
}