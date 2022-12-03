#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <xmmintrin.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define sq(x) (x) * (x)
#define tp int64_t

tp f[50003], s[50003];

signed main() {
  tp n, l;
  memset(f, 0x3f, sizeof f);
  *f = 0;
  scanf("%ld%ld", &n, &l);
  for (tp i = 1, endi = n - (n & 3); i <= endi; i += 4) {
    scanf("%ld%ld%ld%ld", s + i, s + i + 1, s + i + 2, s + i + 3);
    s[i + 3] += s[i + 2] += s[i + 1] += s[i] += s[i - 1];
  }
  for (tp x = n - (n & 3) + 1; x <= n; ++x) {
    scanf("%ld", s + x);
    s[x] += s[x - 1];
  }
  for (tp i = 1; i <= n; i += 2) {
    for (tp j = 0; j < i; j += 2) {
      if (f[j] + sq(i - j - 1 + s[i] - s[j] - l) < f[i]) {
        f[i] = f[j] + sq(i - j - 1 + s[i] - s[j] - l);
      }
      if (f[j + 1] + sq(i - j - 2 + s[i] - s[j + 1] - l) < f[i]) {
        f[i] = f[j + 1] + sq(i - j - 2 + s[i] - s[j + 1] - l);
      }
    }
    if (i & 1) {
      if (f[i - 1] + sq(s[i] - s[i - 1] - l) < f[i]) {
        f[i] = f[i - 1] + sq(s[i] - s[i - 1] - l);
      }
    }
    for (tp j = 0; j <= i; ++j) {
      if (f[j] + sq(i - j + s[i + 1] - s[j] - l) < f[i + 1]) {
        f[i + 1] = f[j] + sq(i - j + s[i + 1] - s[j] - l);
      }
    }
  }
  if (n & 1) {
    for (tp j = 0; j < n; ++j) {
      if (f[j] + sq(n - j - 1 + s[n] - s[j] - l) < f[n]) {
        f[n] = f[j] + sq(n - j - 1 + s[n] - s[j] - l);
      }
    }
  }
  printf("%ld", f[n]);
  return 0;
}