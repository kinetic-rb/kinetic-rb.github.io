#include <iostream>

using namespace std;
using dt = long long;

dt num[200003];

signed main() {
  dt r, l = 1, ls = 0, rs = 0, m = 0;
  cin >> r;
  for (dt i = 1; i <= r; ++i) {
    cin >> num[i];
  }
  while (l - r < 2) {
    if (ls < rs) {
      ls += num[l++];
    } else if (rs < ls) {
      rs += num[r--];
    } else {
      if (ls > m) {
        m = ls;
      }
      ls += num[l++];
      rs += num[r--];
    }
  }
  cout << m;
  return 0;
}