#include <iostream>

using namespace std;

int num[305], sum[305], f[3][305][305];

int main() {
  int n, mx = -1, mi = 0x7fffffff, m;
  cin >> n;
  m = n << 1;
  for(int i = 1; i <= m; i++) {
    if(i <= n)
      cin >> num[i];
    num[i + n] = num[i];
    sum[i] = sum[i - 1] + num[i];
  }
  for(int p = 1; p < n; p++)
    for(int i = 1, j = 1 + p; (i < m) && (j < m); i++, j = i + p) {
      f[2][i][j] = 0x7fffffff;
      for(int k = i; k < j; k++) {
        f[1][i][j] = max(f[1][i][j], f[1][i][k] + f[1][k + 1][j] + sum[j] - sum[i - 1]);
        f[2][i][j] = min(f[2][i][j], f[2][i][k] + f[2][k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  for(int i = 1; i <= n; i++) {
    mx = max(mx, f[1][i][i + n - 1]);
    mi = min(mi, f[2][i][i + n - 1]);
  }
  cout << mi << '\n' << mx;
  return 0;
}