#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][15], i, j, k, b, x, y, r, s;
int main() {
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> b >> x >> y >> r >> s;
    for (j = x; j <= x + r - 1; j++)
      for (k = y; k <= y + s - 1; k++) a[j][k] = b;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cout << a[i][j];
    cout << endl;
  }
  return 0;
}