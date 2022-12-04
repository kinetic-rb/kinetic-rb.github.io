#include <iostream>
#include <cmath>

using namespace std;

inline bool ip(int &n) {
  if (n == 1) {
    return false;
  }
  for (register int i = 2; i * i <= n; i++) {
    if (!(n % i)) {
      return false;
    }
  }
  return true;
}

int main() {
    ios::sync_with_stdio(false);
  register int t, n;
  for (cin >> t; t--; cout << (ip(n) ? "Yes
" : "No
"))
    cin >> n;
  return 0;
}