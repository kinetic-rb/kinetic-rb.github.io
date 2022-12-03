#include <iostream>

using namespace std;

int main() {
  int x, n, ans;
  cin >> x >> n;
  ans = x * n;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    ans -= y;
  }
  cout << ans + x;
  return 0;
}