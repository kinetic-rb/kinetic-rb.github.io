#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 200003;

tp r[Hat_N];

signed main() {
  tp t;
  cin >> t;
  while (t--) {
    static tp L = 1, R = 0;
    tp id;
    char op;
    cin >> op >> id;
    if (op == 'L') {
      r[id] = --L;
    } else if (op == 'R') {
      r[id] = ++R; 
    } else {
      cout << min(r[id] - L, R - r[id]) << '\n';
    }
  }
  return 0;
}