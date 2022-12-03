#include <iostream>

using namespace std;

int ps[101][101];

int main() {
  int n, m, MAX = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> ps[i][j];
    }
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= m; y++) {
      for (int xx = x; xx <= n; xx++) {
        for (int yy = y; yy <= m; yy++) {
          if (yy - y == xx - x) {
            bool al = true;
            for (int i = x; i <= xx && al; i++)
              for (int j = y; j <= yy; j++)
                if (!ps[i][j]) {
                  al = false;
                  break;
                }
            if (al) {
              MAX = max(MAX, yy - y + 1);
            }
          }
        }
      }
    }
  }
  cout << MAX;
  return 0;
}