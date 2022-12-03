#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int f[100000];
int n;

inline int fs(int mi, int val) {
  int qloc = 0;
  for (int pew = 1 << mi; pew; pew >>= 1) {
    int loc = qloc + pew;
    if (loc <= n and f[loc] < val)
      qloc = loc;
  }
  return qloc + 1;
}

int main() {
  memset(f, -0x3f, sizeof f);
  int m, sum = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> f[i];
  for (stable_sort(f + 1, f + n + 1); m--;) {
    int x, y;
    cin >> x;
    y = fs(27, x);
    sum += min(abs(x - f[y]), min(abs(x - f[y - 1]), abs(x - f[y + 1])));
  }
  cout << sum;
  return 0;
}