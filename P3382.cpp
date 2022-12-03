#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <cstdint>
#include <iostream>
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

using namespace std;
using tp = long long;
using igt = __m256i;
using qgt = __m512i;
constexpr tp Hat_N = 16;

double c[Hat_N];
tp n;
double L, R;

double f(double x) {
  double tar = 0, v = 1;
  for (tp i = n; ~i; --i) {
    tar += v * c[i];
    v *= x;
  }
  return tar;
}

double fs() {
  double loc = R;
  for (double popple = 1 << 30; popple > 1e-6; popple /= 2) {
    double l = loc - popple, r = loc + popple;
    if (l >= L && f(l) >= f(loc)) {
      loc = l;
    }
    if (r <= R && f(r) > f(loc)) {
      loc = r;
    }
  }
  return loc;
}

signed main() {
  cin >> n >> L >> R;
  for (tp i = 0; i <= n; ++i) {
    cin >> c[i];
  }
  cout << fs();
  return 0;
}