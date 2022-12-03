#include <iostream>

using namespace std;
using tp = long long;
constexpr tp _MOD_ = 2179217;

tp ra() {
  tp __val;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  __val = c & 15;
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) {
    __val = (__val * 10 + (c & 15)) % _MOD_;
  }
  return __val;
}

signed main() {
  tp t = ra();
  while (t--) {
    tp a = ra(), b = ra(), c = ra();
    puts(a * b % _MOD_ == c ? "YES" : "NO");
  }
}