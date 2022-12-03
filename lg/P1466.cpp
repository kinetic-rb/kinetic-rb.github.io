#include <iostream>
#define int long long

using namespace std;

int n, f[40][800];

signed main() {
  cin >> n;
  if (((1 + n) * n >> 1) & 1) {
    cout << 0;
    return 0;
  }
  **f = 1;
  for (int i = 1; i <= n; i++)
    for (int j = (1 + n) * n >> 1; j > -1; j--) {
      f[i][j] += f[i - 1][j];
      if (j - i > -1)
        f[i][j] += f[i - 1][j - i];
    }
  cout << (f[n][(1 + n) * n >> 2] >> 1);
  return 0;
}