#include <iostream>
#define int long long

using namespace std;

int f[1000005];

template <typename comp>
inline int fs(int mi, comp cmp) {
  int qloc = 0;
  for (int pew = 1 << mi; pew; pew >>= 1) {
    int loc = qloc + pew;
    if (cmp(loc))
      qloc = loc;
  }
  return qloc;
}

signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> f[i];
  cout << fs(29, [&](int x) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
      if (f[i] > x)
        sum += f[i] - x;
    return sum >= m;
  });
  return 0;
}