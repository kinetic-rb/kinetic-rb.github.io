#include <iostream>
#include <array>

using namespace std;

array<int, 10001> sx, sy, ex, ey, id;

int main() {
  int n, x, y, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
  }
  cin >> x >> y;
  for (int i = n - 1; i > -1; i--) {
    if (x >= sx[i] && x <= sx[i] + ex[i] && y >= sy[i] && y <= sy[i] + ey[i]) {
        cout << ++i;
        return 0;
    }
  }
  cout << -1;
  return 0;
}