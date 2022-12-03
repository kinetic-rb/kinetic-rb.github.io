#include <iostream>

using namespace std;
using tp = int64_t;

void Core() {
  tp n, a, b;
  cin >> n >> a >> b;
  if (a * 2 < b) {
    cout << n * a << '\n';
  } else {
    cout << (n >> 1) * b + (n & 1) * a << '\n';
  }
}

signed main() {
  tp __Tests__ = 1;
  cin >> __Tests__;
  while (__Tests__--) {
    Core();
  }
  return 0;
}