#include <iostream>

using namespace std;

int num[249], f[249][249];

int main() {
  int n, MAX = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    f[i][i] = num[i];
    MAX = max(MAX, f[i][i]);
  }
  for (int len = 2; len <= n; len++)
    for (int i = 1, j; (j = i + len - 1) <= n; ++i) {
      for (int k = i; k < j; k++)
        if (f[i][k] == f[k + 1][j])
          f[i][j] = max(f[i][j], f[k + 1][j] + 1);
      MAX = max(MAX, f[i][j]);
    }
  cout << MAX;
  return 0;
}