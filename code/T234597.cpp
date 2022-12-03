#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

namespace Anonymous {
constexpr size_t __Buf_Size__ = 32767;
bool State = 1;
char *__buf = (char*)malloc(__Buf_Size__), *__s = nullptr, *__e = nullptr;

template <typename Typex>
void re(Typex&&);
template <typename Typex, typename... Typey>
void re(Typex&&, Typey&&...);
}  // namespace Anonymous
using Anonymous::re;
using namespace std;
using tp = long long;
using igt = __m256i;
using qgt = __m512i;
constexpr bool __TEST_CASES__ = 0;
constexpr tp Hat_N = 103, _MOD_ = 1e9 + 7;

signed __PRE__() {
  return 0;
}

tp a[Hat_N][Hat_N], b[Hat_N][Hat_N], c[Hat_N][Hat_N];
tp n, m;

void mul(tp a[][Hat_N], tp b[][Hat_N]) {
  for (tp i = 0; i < m; ++i) {
    for (tp j = 0; j < m; ++j) {
      c[i][j] = 0;
      for (tp k = 0; k < m; ++k) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % _MOD_;
      }
    }
  }
}

void Make() {
  for (tp i = 0; i < m; ++i) {
    b[i][i] = 1;
    for (tp j = i; j < m; ++j) {
      a[i][j] = 1;
    }
  }
}

signed __CORE__() {
  cin >> n >> m;
  Make();
  while (n) {
    if (n & 1) {
      mul(b, a);
      copy(*c, *c + Hat_N * Hat_N, *b);
    }
    mul(a, a);
    copy(*c, *c + Hat_N * Hat_N, *a);
    n >>= 1;
  }
  cout << b[0][m - 1];
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
      re(__TEST_COUNT__);
    }
    __NOT_READED__ = 0;
  }
  if (__TEST_COUNT__-- && (main() || __CORE__())) {
    return -1;
  }
  return 0;
}

namespace Anonymous {
template <typename Typex>
void re(Typex&& __v) {
  bool f = 0;
  char __ch;
  auto __fetch = [&__ch]() {
    if (__s == __e) {
      __s = __buf;
      __e = __s + fread(__buf, 1, __Buf_Size__, stdin);
      if (__s == __e) {
        State = 0;
        __ch = -1;
      }
    }
    __ch = *__s++;
  };
  for (__fetch(); __ch < 48 || __ch > 57; __fetch()) {
    f |= __ch == 45;
  }
  __v = __ch & 15;
  for (__fetch(); __ch > 47 && __ch < 58; __fetch()) {
    __v += __v << 2;
    __v += __v + (__ch & 15);
  }
  if (f) {
    __v = (~__v) + 1;
  }
}

template <typename Typex, typename... Typey>
void re(Typex&& __v, Typey&&... __V) {
  re(__v);
  if (State) {
    re(__V...);
  }
}
}  // namespace Anonymous