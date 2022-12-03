#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <numeric>
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

using namespace std;
using tp = long long;
using igt = __m256i;
using qgt = __m512i;
constexpr tp Hat_N = 12, Hat_C = 13;

tp f[Hat_N][Hat_C];

tp Calc(tp o) {
  tp p = 1;
  string s;
  cin >> s;
  memset(f, 0, sizeof f);
  for (tp i = s[0] - '1'; i; --i) {
    f[0][i] = 1;
  }
  for (tp i = 0; i < s.size() - 1; ++i) {
    for (tp j = 0; j < 10; ++j) {
      for (tp k = 0; k < 10; ++k) {
        f[i + 1][k] += f[i][j] * (abs(j - k) >= 2);
      }
    }
    for (tp k = 1; k < 10; ++k) {
      ++f[i + 1][k];
    }
    for (tp k = 0; k < (s[i + 1] & 15); k++) {
      f[i + 1][k] += p * (abs((s[i] & 15) - k) >= 2);
    }
    p &= abs(s[i] - s[i + 1]) >= 2;
  }
  return accumulate(f[s.size() - 1], f[s.size() - 1] + 10, o & p);
}

signed main() {
  tp l = Calc(0), r = Calc(1);
  cout << r - l;
  return 0;
}