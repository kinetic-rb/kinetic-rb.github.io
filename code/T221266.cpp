#include <iostream>

using namespace std;

const int kMaxN = 101;
const int kM = 1000000007;

long long a[kMaxN][kMaxN];
int n, m, t, x1, y1, x2, y2;

int main() {
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      a[i][j] = (a[i][j - 1] + a[i][j]) % kM;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = (a[i - 1][j] + a[i][j]) % kM;
    }
  }
  while (t--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] + 2 * kM) % kM << '\n';
  }
  return 0;
}