#include <iostream>

using namespace std;
using tp = int_fast32_t;

signed main() {
  tp n;
  string s;
  cin >> n >> s;
  for (tp i = 0, cnt = 0; i < n; i += ++cnt) {
    cout << s[i];
  }
  return 0;
}