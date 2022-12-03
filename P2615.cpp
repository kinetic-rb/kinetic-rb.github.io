#include <iostream>

using namespace std;

int mp[40][40];

int main() {
  int n;
  cin >> n;
  for (int step = 1; step <= n * n; step++) {
    static int llx, lly;
    if (step == 1)
      mp[llx = 1][lly = n / 2 + 1] = step;
    else if (llx == 1 && lly != n)
      mp[llx = n][++lly] = step;
    else if (llx != 1 && lly == n)
      mp[--llx][lly = 1] = step;
    else if (llx == 1 && lly == n)
      mp[++llx][lly] = step;
    else if (llx != 1 && lly != n)
      mp[llx - 1][lly + 1] ? mp[++llx][lly] = step : mp[--llx][++lly] = step;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      cout << mp[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}