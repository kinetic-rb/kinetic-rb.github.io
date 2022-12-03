#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#define ra __Read_int()

using namespace std;
using tp = long long;

tp __Read_int() {
  tp x;
  scanf("%lld", &x);
  return x;
}

tp get(tp w, tp a, tp b, tp c) {
  return (-b + w * sqrt(b * b - 4 * a * c)) / (2 * a);
}

signed main() {
  tp k = ra;
  while (k--) {
    tp b = ra, e = ra, d = ra, a = b - e * d + 2;
    tp p = get(1, -1, a, -b), q = get(-1, -1, a, -b);
    if (max(p, q) > b || min(p, q) < -b || b != p * q || e * d != (p - 1) * (q - 1) + 1) {
      puts("NO");
    } else {
      printf("%lld %lld
", min(p, q), max(p, q));
    }
  } 
  return 0;
}