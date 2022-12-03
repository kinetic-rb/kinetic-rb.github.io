#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <cstdint>
#include <iostream>
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

namespace Anonymous {
bool State = 1;

char re();
void re(char*);
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
constexpr tp Hat_S = 200000003;

char b[Hat_S];

signed __PRE__() {
  return 0;
}

/*
$$\varphi(x) = x \cdot \frac{p_1 - 1}{p_1} \cdot \frac{p_2 - 1}{p_2} \cdot
\frac{p_3 - 1}{p_3} \cdot \ldots \cdot \frac{p_n - 1}{p_n}$$
*/

tp phi(tp x) {
  tp tar = x;
  for (tp i = 2; i * i <= x; ++i) {
    if (!(x % i)) {
      tar = tar / i * (i - 1);
      while (!(x % i)) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    tar = tar / x * (x - 1);
  }
  return tar;
}

tp qpow(tp x, tp y, tp mod) {
  tp tar = 1;
  while (y) {
    if (y & 1) {
      tar = tar * x % mod;
    }
    x = x * x % mod;
    y >>= 1;
  }
  return tar;
}

signed __CORE__() {
  char* b = ::b;
  tp a, m, tb = 0, pm, c = 0;
  cin >> a >> m >> ::b;
  pm = phi(m);
  while (*b) {
    tb = tb * 10 + (*b++ & 15);
    c |= tb >= pm;
    tb %= pm;
  }
  tb += pm * c;
  cout << qpow(a, tb, m);
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
constexpr size_t __Buf_Size__ = 65535;
char __ch = -1;
char *__buf = (char*)malloc(__Buf_Size__), *__s = nullptr, *__e = nullptr;

void __fetch() {
  if (__s == __e) {
    __s = __buf;
    if (__e = __s + fread(__buf, 1, __Buf_Size__, stdin); __s == __e++) {
      State = 0;
      __ch = -1;
      return;
    }
  }
  __ch = *__s++;
}

char re() {
  char ___ch = -1;
  if (State) {
    while (__ch == 32 || __ch == 10 || __ch == 13 || __ch == -1 || __ch == 9 ||
           __ch == 12 || __ch == 11) {
      __fetch();
    }
    ___ch = __ch;
    __fetch();
  }
  return ___ch;
}

void re(char* __v) {
  if (State) {
    while (__ch == 32 || __ch == 10 || __ch == 13 || __ch == -1 || __ch == 9 ||
           __ch == 12 || __ch == 11) {
      __fetch();
    }
    while (__ch != 32 && __ch != 10 && __ch != 13 && __ch != -1 && __ch != 9 &&
           __ch != 12 && __ch != 11) {
      *__v++ = __ch;
      __fetch();
    }
  }
  *__v = 0;
}

template <typename Typex>
void re(Typex&& __v) {
  bool __f = 0;
  if (State) {
    for (; __ch < 48 || __ch > 57; __fetch()) {
      __f |= __ch == 45;
    }
    __v = __ch & 15;
    for (__fetch(); __ch > 47 && __ch < 58; __fetch()) {
      __v += __v << 2;
      __v += __v + (__ch & 15);
    }
    if (__f) {
      __v = (~__v) + 1;
    }
  } else {
    __v = 0;
  }
}

template <typename Typex, typename... Typey>
void re(Typex&& __v, Typey&&... __V) {
  re(__v);
  re(__V...);
}
}  // namespace Anonymous