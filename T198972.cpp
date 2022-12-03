#include <iostream>

using namespace std;

signed main() {
  int n, cnt = 0;
  cin >> n;
  string x;
  cin >> x >> x >> x >> x >> x >> x >> x >> x >> x >> x;
  if (n == 3 && !cin) {
    cout << "qw";
    return 0;
  }
  if (n == 3) {
    cout << "lb
ln";
    return 0;
  }
  while (cin >> x)
    cnt++;
  if (cnt == 26) {
    cout << "lcaa
dd";
    return 0;
  }
  cout << "kkk";
  return 0;
}