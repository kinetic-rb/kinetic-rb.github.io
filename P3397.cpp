#include <iostream>

using namespace std;

short b[1001][1001];

int main() {
  int n, t;
  ios_base::sync_with_stdio(false);
  for (cin >> n >> t; t--;) {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    for (int i = sx; i <= ex; i++)
      for (int j = sy; j <= ey; j++)
        b[i][j]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cout << b[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}