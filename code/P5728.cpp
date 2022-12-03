#include <iostream>

using namespace std;

int a[1010][5], sum[1010];

int main() {
  int cnt = 0, n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1] >> a[i][2] >> a[i][3];
    sum[i] = a[i][1] + a[i][2] + a[i][3];
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (abs(a[i][1] - a[j][1]) < 6 && abs(a[i][2] - a[j][2]) < 6 && abs(a[i][3] - a[j][3]) < 6 && abs(sum[i] - sum[j]) < 11)
        cnt++;
  cout << cnt;
  return 0;
}