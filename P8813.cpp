#include <iostream>
#define ra __Read_int()

using namespace std;
using tp = long long;

tp __Read_int() {
  tp x;
  scanf("%lld", &x);
  return x;
}

constexpr tp c_Limit = 1000000000;

signed main() {
  tp a = ra, b = ra, tar = 1;
  while (b) {
    if (b & 1) {
      if (tar * a > c_Limit) {
        puts("-1");
        return 0;
      }
      tar *= a;
    }
    a *= a;
    b >>= 1;
    if (a > c_Limit && b) {
      puts("-1");
      return 0;
    }
  }
  printf("%lld
", tar);
  return 0;
}