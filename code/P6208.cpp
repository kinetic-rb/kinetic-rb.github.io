#include <iostream>

using namespace std;

int f[1001][1001], num[1001][1001];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> num[i][j];
  f[1][1] = num[1][1];
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n && j <= i; j++)
      f[j][i] = max(f[j - 1][i - 1], max(f[j + 1][i - 1], f[j][i - 1])) + num[j][i];
  cout << f[n][m];
  return 0;
}