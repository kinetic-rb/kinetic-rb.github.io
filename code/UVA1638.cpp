#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 25;

ll n, l, r, t, f[N][N][N];

int main() {
  f[0][0][1] = 1;
  for (int i = 1; i < 21; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 1; k <= i; k++) {
        f[i][j][k] = (f[i - 1][j - 1][k] + f[i - 1][j][k - 1] + f[i - 1][j][k] * (i - 2));
      }
    }
  }
  for (cin >> t; t--;) {
    cin >> n >> l >> r;
    cout << f[n][l][r] << '\n';
  }
  return 0;
}