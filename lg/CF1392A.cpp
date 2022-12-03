#include <iostream>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    bool diff = 0;
    cin >> n >> x;
    for (int i = 1; i < n; ++i) {
      int y;
      cin >> y;
      if (x != y) {
        diff = 1;
      }
    }
    cout << (diff ? 1 : n) << '\n';
  }
  return 0;
}