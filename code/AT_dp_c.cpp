#include <iostream>

using namespace std;

int a[100005], b[100005], c[100005], f[100005][4];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i];
  for (int i = 1; i <= n; i++) {
    f[i][1] = max(f[i - 1][2],f[i - 1][3]) + a[i];
    f[i][2] = max(f[i - 1][1],f[i - 1][3]) + b[i];
    f[i][3] = max(f[i - 1][1],f[i - 1][2]) + c[i];
  }
  cout << max(f[n][1], max(f[n][2], f[n][3]));
  return 0;
}