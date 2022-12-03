#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int N = 1005;

struct E {
  int x, y;
  double z;
} e[N * N];

int n, k, f[N], c, a[N], b[N], m;
double r;

int G(int x) {
  return f[x] = f[x] == x ? x : G(f[x]);
}

double D(double a, double b) {
  return sqrt(a * a + b * b);
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    f[i] = i;
    for (int j = 1; j < i; j++) {
      e[++m] = {i, j, D(a[i] - a[j], b[i] - b[j])};
    }
  }
  sort(e + 1, e + m + 1, [](E x, E y) { return x.z < y.z; });
  for (int i = 1; c <= n - k; i++) {
    if (G(e[i].x) != G(e[i].y)) {
      r = max(r, e[i].z);
      c++;
      f[G(e[i].x)] = G(e[i].y);
    }
  }
  cout << fixed << setprecision(2) << r;
  return 0;
}