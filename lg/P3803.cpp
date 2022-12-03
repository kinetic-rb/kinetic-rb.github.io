#include <emmintrin.h>
#include <immintrin.h>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#pragma GCC target("sse,avx2,popcnt,tune=native")

using namespace std;
using tp = long long;
constexpr bool __TEST_CASES__ = 0;
constexpr tp Hat_N = 4e6 + 3;
constexpr double Pi = 3.14159265358979323;

signed __PRE__() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 0;
}

struct Rcomplex {
  double x, y;

  Rcomplex() = default;
  Rcomplex(const __m128d& m) : x(m[0]), y(m[1]) {}
  Rcomplex(double _x, double _y) : x(_x), y(_y) {}
  Rcomplex operator+(const Rcomplex& item) const {
    return _mm_add_pd(_mm_set_pd(y, x), _mm_set_pd(item.y, item.x));
  }
  Rcomplex operator-(const Rcomplex& item) const {
    return _mm_sub_pd(_mm_set_pd(y, x), _mm_set_pd(item.y, item.x));
  }
  Rcomplex operator*(const Rcomplex& item) const {
    __m256d t = _mm256_mul_pd(_mm256_set_pd(x, y, x, y),
                              _mm256_set_pd(item.x, item.y, item.y, item.x));
    return Rcomplex(t[3] - t[2], t[1] + t[0]);
  }
  Rcomplex operator/(const Rcomplex& item) const {
    __m128d p =
        _mm_mul_pd(_mm_set_pd(item.x, item.y), _mm_set_pd(item.x, item.y));
    __m256d t = _mm256_mul_pd(_mm256_set_pd(x, y, x, y),
                              _mm256_set_pd(item.x, item.y, item.y, item.x));
    return _mm_div_pd(_mm_set_pd(t[0] - t[1], t[3] + t[2]),
                      _mm_set1_pd(p[0] + p[1]));
  }
  Rcomplex& operator+=(const Rcomplex& item) { return *this = *this + item; }
  Rcomplex& operator-=(const Rcomplex& item) { return *this = *this - item; }
  Rcomplex& operator*=(const Rcomplex& item) { return *this = *this * item; }
  Rcomplex& operator/=(const Rcomplex& item) { return *this = *this / item; }
};

enum DFT_or_IDFT { DFT, IDFT };

Rcomplex x[Hat_N], y[Hat_N], sav[Hat_N];

void FFT(Rcomplex* F, size_t size, DFT_or_IDFT type) {
  Rcomplex *FL = F, *FR = F + (size >> 1);
  Rcomplex c(cos(2 * Pi / size), sin(2 * Pi / size)), now(1, 0);
  if (size == 1) {
    return;
  }
  if (type == IDFT) {
    c.y = -c.y;
  }
  for (tp i = 0; i < size; ++i) {
    sav[i] = F[i];
  }
  for (tp i = 0, endi = size >> 1; i < endi; ++i) {
    FL[i] = sav[i << 1];
    FR[i] = sav[i << 1 | 1];
  }
  FFT(FL, size >> 1, type);
  FFT(FR, size >> 1, type);
  for (tp i = 0, endi = size >> 1; i < endi; ++i) {
    sav[i] = FL[i] + now * FR[i];
    sav[i + (size >> 1)] = FL[i] - now * FR[i];
    now *= c;
  }
  for (tp i = 0; i < size; ++i) {
    F[i] = sav[i];
  }
}

signed __CORE__() {
  tp n, m;
  cin >> n >> m;
  for (tp i = 0; i <= n; ++i) {
    cin >> x[i].x;
  }
  for (tp i = 0; i <= m; ++i) {
    cin >> y[i].x;
  }
  m += n;
  for (n = 1; n <= m; n <<= 1) {
  }
  FFT(x, n, DFT);
  FFT(y, n, DFT);
  for (tp i = 0; i < n; ++i) {
    x[i] *= y[i];
  }
  FFT(x, n, IDFT);
  for (tp i = 0; i <= m; ++i) {
    cout << tp(x[i].x / n + 0.49) << ' ';
  }
  return 0;
}

signed main() {
  static bool __NOT_READED__ = 1;
  static tp __TEST_COUNT__ = 1;
  if (__NOT_READED__) {
    if (__PRE__()) {
      return -1;
    }
    if (__TEST_CASES__) {
      cin >> __TEST_COUNT__;
    }
    __NOT_READED__ = 0;
  }
  if (__TEST_COUNT__-- && (main() || __CORE__())) {
    return -1;
  }
  return 0;
}