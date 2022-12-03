#include <iostream>

using namespace std;

int num[1001], f[1001][1001];

int main() {
  int n, ans;
  cin >> n;
  ans = n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    f[0][i] = 1;
  }
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++) {
      f[j][i] = f[0][j];
      for (int k = 0; k < j; k++)
        if (num[j] << 1 == num[k] + num[i])
          f[j][i] = (f[j][i] + f[k][j]) % 998244353;
      ans = (ans + f[j][i]) % 998244353;
    }
  cout << ans;
  return 0;
}