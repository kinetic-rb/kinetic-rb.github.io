#include <cstring>
#include <iostream>

using namespace std;

signed main() {
  static long long w[1005], s[1005];
  static double f[1005];
  long long n, k;
  double m;
  cin >> k >> m >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> w[i] >> s[i];
    f[i] = 1.79769e308;
  }
  for (long long r = 1; r <= n; r++) {
    long long l = r, sum = w[l], speed = s[l];
    while (l && sum <= k) {
      f[r] = min(f[r], f[--l] + m / speed);
      sum += w[l];
      speed = min(speed, s[l]);
    }
  }
  printf("%.1lf", f[n] * 60);
  return 0;
}