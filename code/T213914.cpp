#include <algorithm>
#include <iostream>

using namespace std;
using \u6d1b\u8c37 = long long;
constexpr \u6d1b\u8c37 HAT_M = 100003;

\u6d1b\u8c37 \u6570[HAT_M];

int main() {
  bool f = false;
  string \u5b57\u7b26\u4e32;
  \u6d1b\u8c37 \u4e58;
  cin >> \u5b57\u7b26\u4e32 >> \u4e58;
  reverse(\u5b57\u7b26\u4e32.begin(), \u5b57\u7b26\u4e32.end());
  for (\u6d1b\u8c37 i = 0; i < \u5b57\u7b26\u4e32.size(); ++i) {
    \u6570[i] = \u5b57\u7b26\u4e32[i] ^ 48;
    \u6570[i] *= \u4e58;
  }
  for (\u6d1b\u8c37 i = 0; i < \u5b57\u7b26\u4e32.size(); ++i) {
    \u6570[i + 1] += \u6570[i] / 10;
    \u6570[i] %= 10;
  }
  for (\u6d1b\u8c37 i = HAT_M - 2; ~i; --i) {
    if (\u6570[i]) {
      f = true;
    }
    if (f) {
      cout << \u6570[i];
    }
  }
  if (!f) {
    cout << 0;
  }
  return 0;
}