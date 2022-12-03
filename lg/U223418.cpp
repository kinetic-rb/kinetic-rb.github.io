#include <iostream>

using namespace std;
using tp = int_fast32_t;
constexpr tp Hat_S = 303;

tp val[Hat_S][Hat_S][Hat_S];

signed main() {
  tp n, cnt = 0;
  cin >> n;
  while (n--) {
    tp x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    ++x2;
    ++y2;
    ++z2;
    ++val[x1][y1][z1];
    --val[x1][y1][z2];
    --val[x1][y2][z1];
    ++val[x1][y2][z2];
    --val[x2][y1][z1];
    ++val[x2][y1][z2];
    ++val[x2][y2][z1];
    --val[x2][y2][z2];
  }
  cin >> n;
  for (tp i = 1; i < Hat_S; ++i) {
    for (tp j = 1; j < Hat_S; ++j) {
      for (tp k = 1; k < Hat_S; ++k) {
        val[i][j][k] += val[i - 1][j][k] + val[i][j - 1][k] + val[i][j][k - 1] -
                        val[i - 1][j - 1][k] - val[i - 1][j][k - 1] -
                        val[i][j - 1][k - 1] + val[i - 1][j - 1][k - 1];
        cnt += val[i][j][k] == n;
      }
    }
  }
  cout << cnt;
  return 0;
}