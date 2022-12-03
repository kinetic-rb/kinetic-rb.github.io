#include <iostream>

using namespace std;

long long num[3005], f[3005][3005], p[3005][3005];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  for (int i = 1; i <= n; i++) {
    f[i][i] = p[i][i] = num[i];
    for (int j = i + 1; j <= n; j++)
      p[i][j] = p[i][j - 1] + num[j];
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= n - i; j++)
      f[j][j + i] = p[j][j + i] - min(f[j][j + i - 1], f[j + 1][j + i]);
  cout << (f[1][n] << 1) - p[1][n];
  return 0;
}