#include <iostream>
#include <map>

using namespace std;
using tp = int32_t;

map<tp, map<tp, double>> val;

signed main() {
  tp n;
  cin >> n;
  for (tp i = 0; i < n; ++i) {
    for (tp j = 0; j <= n; ++j) {
      cin >> val[i][j];
    }
  }
  for (tp i = 0; i < n; ++i) {
    tp max = i;
    for (tp j = i + 1; j < n; ++j) {
      if (abs(val[j][i]) > abs(val[max][i])) {
        max = j;
      }
    }
    for (tp j = 0; j <= n; ++j) {
      swap(val[i][j], val[max][j]);
    }
    if (!val[i][i]) {
      puts("No Solution");
      return 0;
    }
    for (tp j = 0; j < n; ++j) {
      if (i ^ j) {
        double temp = val[j][i] / val[i][i];
        for (tp k = i + 1; k <= n; ++k) {
          val[j][k] -= val[i][k] * temp;
        }
      }
    }
  }
  for (tp i = 0; i < n; ++i) {
    printf("%.2lf
", val[i][n] / val[i][i]);
  }
  return 0;
}