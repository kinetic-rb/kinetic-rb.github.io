#include <iostream>
#define int unsigned

using namespace std;

int num[5005][5005];

signed main() {
  ios_base::sync_with_stdio(false);
  int n, m, MAX = 0;
  for (cin >> n >> m; n--;) {
    int x, y;
    cin >> x >> y;
    cin >> num[x + 1][y + 1];
  }
  for (int i = 2; i < 5002; i++) {
    num[1][i] += num[1][i - 1];
    num[i][1] += num[i - 1][1];
  }
  for (int i = 2; i < 5002; i++)
    for (int j = 2; j < 5002; j++)
      num[i][j] += num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1];
  for (int i = m; i < 5002; i++)
    for (int j = m; j < 5002; j++)
      MAX = max(MAX,
                num[i][j] - num[i - m][j] - num[i][j - m] + num[i - m][j - m]);
  cout << MAX;
  return 0;
}