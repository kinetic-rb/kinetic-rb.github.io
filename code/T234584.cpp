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
constexpr tp _MOD_ = 1000000007;

igt multi(igt x, igt y) {
  igt tar = _mm256_add_epi64(
      _mm256_mul_epi32(_mm256_set_epi64x(x[2], x[2], x[0], x[0]),
                       _mm256_set_epi64x(y[1], y[0], y[1], y[0])),
      _mm256_mul_epi32(_mm256_set_epi64x(x[3], x[3], x[1], x[1]),
                       _mm256_set_epi64x(y[3], y[2], y[3], y[2])));
  return _mm256_set_epi64x(tar[3] % _MOD_, tar[2] % _MOD_, tar[1] % _MOD_,
                           tar[0] % _MOD_);
}

tp fib(tp n) {
  igt ans = _mm256_set_epi64x(1, 0, 0, 1), m = _mm256_set_epi64x(0, 1, 1, 1);
  while (n) {
    if (n & 1) {
      ans = multi(ans, m);
    }
    m = multi(m, m);
    n >>= 1;
  }
  return ans[0];
}

signed main() {
  tp n;
  cin >> n;
  cout << fib(n);
  return 0;
}