#include <iostream>

using namespace std;

int m, y, t;

inline void out(double x) {
  printf("%.1lf", x * 100);
  exit(0);
}

inline void solve(double l, double r) {
  double k = (l + r) / 2, u = r - l;
  double a = m;
  if (u < 0.0001)
    out(k);
  for (int i = 1; i <= t; i++)
    a = a * (1 + k) - y;
  if (a > 0)
    solve(l, k);
  if (a < 0)
    solve(k, r);
  if (!a)
    out(k);
}

int main() {
  cin >> m >> y >> t;
  solve(0, 100);
  return 0;
}