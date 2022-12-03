#include <iostream>

using namespace std;
using dt = long long;
constexpr dt Hat_N = 13;

char m[Hat_N][Hat_N];

signed main() {
  dt n, k;
  cin >> n >> k;
  for (dt i = 0; i < n; ++i) {
    for (dt j = 0; j < n; ++j) {
      cin >> m[i][j];
    }
  }
  for (dt i = 0; i < n * k; i++) {
    for (dt j = 0; j < n * k; j++) {
      cout << m[i / k][j / k];
    }
    cout << '\n';
  }
  return 0;
}