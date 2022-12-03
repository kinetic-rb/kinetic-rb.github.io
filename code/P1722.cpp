#include <iostream>

using namespace std;

int f[1001][1001];

int main() {
  int n;
  cin >> n;
  f[1][1] = 1;
  for (int i = 2; i <= n << 1; i++)
    for (int j = (i + 1) >> 1; j <= i; j++)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % 100;
  cout << f[n * 2][n];
  return 0;
}