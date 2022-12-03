#include <iostream>
#include <cmath>

using namespace std;

long r;

struct Point {
  long x, y, z;

  void get() { cin >> x >> y >> z; }

  bool operator()(const Point& comp) {
    return sqrt((x - comp.x) * (x - comp.x) + (y - comp.y) * (y - comp.y) +
                (z - comp.z) * (z - comp.z)) <= r;
  }
} p[1001];

long f[1001];

long find(const long& u) {
  return (f[u] == u ? u : f[u] = find(f[u]));
}

signed main() {
  long t;
  for (cin >> t; t--;) {
    bool flag = false;
    long n, h;
    cin >> n >> h >> r;
    for (long i = 1; i <= n; i++)
      f[i] = i;
    r <<= 1;
    for (long i = 1; i <= n; i++)
      p[i].get();
    for (long i = 1; i <= n; i++)
      for (long j = i + 1; j <= n; j++)
        if (p[i](p[j]))
          f[find(i)] = f[find(j)];
    r >>= 1;
    for (long i = 1; i <= n; i++)
      if (p[i].z + r >= h)
        for (long j = 1; j <= n; j++) {
          if (p[j].z - r <= 0 && find(i) == find(j)) {
            flag = true;
            break;
          }
        }
    puts(flag ? "Yes" : "No");
  }
  return 0;
}