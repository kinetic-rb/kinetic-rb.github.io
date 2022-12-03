#include <iostream>

using namespace std;

int f[1001][1001];
int n, m;

int main() {
  cin >> n >> m;
  f[0][1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = (f[i - 1][j] + f[i][j - 1]) % 1000000007;
  cout << f[n][m];
  return 0;
}