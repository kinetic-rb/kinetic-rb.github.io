#include <iostream>
#define int long

using namespace std;

inline int qpew(int a, int n, int m) {
  int ans = 1;
  a %= m;
  while (n) {
    if (n & 1)
      ans = ans * a % m;
    n >>= 1;
    a = (a * a) % m;
  }
  return ans;
}

signed main() {
  int a, n, m;
  cin >> a >> n >> m;
    printf("%d^%d mod %d=%d", a, n, m, qpew(a, n, m));
  return 0;
}