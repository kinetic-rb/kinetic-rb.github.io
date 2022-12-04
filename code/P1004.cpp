#include <iostream>

using namespace std;

int num[15][15], f[15][15][15][15];

int main() {
  int n;
  cin >> n;
  for (int x, y, v; cin >> x >> y >> v, x | y | v; num[x][y] = v)
    ;
  for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++)
      for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
          if (x + y == a + b) {
            f[x][y][a][b] =
                max(f[x][y][a][b], max(f[x - 1][y][a - 1][b],
                                       max(f[x - 1][y][a][b - 1],
                                           max(f[x][y - 1][a - 1][b],
                                               f[x][y - 1][a][b - 1])))) +
                num[x][y] + num[a][b];
            if (x == a && y == b)
              f[x][y][a][b] -= num[x][y];
          }
  cout << f[n][n][n][n];
  return 0;
}