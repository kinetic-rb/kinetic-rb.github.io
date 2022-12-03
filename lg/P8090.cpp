#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_S = 3, Hat_Z = 256;

tp m[Hat_Z], k[Hat_Z];
char n[Hat_S][Hat_S];

signed main() {
  tp cnt = 0;
  for (tp i = 0; i < Hat_S; ++i) {
    for (tp j = 0; j < Hat_S; ++j) {
      cin >> n[i][j];
      ++m[n[i][j]];
    }
  }
  for (tp i = 0; i < Hat_S; ++i) {
    for (tp j = 0; j < Hat_S; ++j) {
      char x;
      cin >> x;
      if (n[i][j] == x) {
        --m[n[i][j]];
        ++cnt;
      } else {
        ++k[x];
      }
    }
  }
  cout << cnt << '\n';
  cnt = 0;
  for (tp i = 'A'; i <= 'Z'; ++i) {
    cnt += min(m[i], k[i]);
  }
  cout << cnt;
  return 0;
}