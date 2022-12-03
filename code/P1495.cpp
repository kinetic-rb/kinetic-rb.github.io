#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

namespace Anonymous {
constexpr size_t __Buf_Size__ = 32768;
bool State = 1;
char *__buf = (char*)malloc(__Buf_Size__ + 1), *__s = nullptr, *__e = nullptr;

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
constexpr tp Hat_N = 13;

tp a[Hat_N], b[Hat_N];

signed __PRE__() {
  *a = 1;
  return 0;
}

void exgcd(tp a, tp b, tp& x, tp& y) {
  if (b) {
    exgcd(b, a % b, x, y);
    y = exchange(x, y) - y * (a / b);
  } else {
    tie(x, y) = make_pair(1, 0);
  }
}

signed __CORE__() {
  tp n, tar = 0;
  re(n);
  for (tp i = 1; i <= n; ++i) {
    re(a[i], b[i]);
    *a *= a[i];
  }
  for (tp i = 1; i <= n; ++i) {
    tp M = *a / a[i], x, y;
    exgcd(M, a[i], x, y);
    tar += b[i] * M * (x < 0 ? x + a[i] : x);
  }
  cout << tar % *a;
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
      ++*__e = 10;
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