#include <cstring>
#include <iostream>
#define Sum(s, e) sum[e] - sum[s - 1]

using namespace std;

int f[301][301], num[301], sum[301];

signed main() {
  memset(f, 127, sizeof f);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    sum[i] = sum[i - 1] + num[i];
    f[1][i] = 0;
  }
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= n - i + 1; j++) {
      for (int k = 1; k < i; k++)
        f[i][j] = min(f[i][j], f[k][j] + f[i - k][j + k] + Sum(j, j + i - 1));
    }
  cout << f[n][1];
  return 0;
}