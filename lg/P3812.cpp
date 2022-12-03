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
constexpr tp Log_Hat_N = 53;

signed __PRE__() {
  return 0;
}

template <size_t __Size>
class Linear_Basis {
  size_t* __p;

 public:
  Linear_Basis() {
    __p = new size_t[__Size];
    for (size_t __i = 0; __i < __Size; ++__i) {
      __p[__i] = 0;
    }
  }

  bool modify(size_t item) {
    size_t __i = __Size;
    while (~--__i) {
      if (item & (1ull << __i)) {
        if (__p[__i]) {
          item ^= __p[__i];
        } else {
          __p[__i] = item;
          return 1;
        }
      }
    }
    return 0;
  }

  size_t query() {
    size_t __tar = 0, __i = __Size;
    while (~--__i) {
      if ((__tar ^ __p[__i]) > __tar) {
        __tar ^= __p[__i];
      }
    }
    return __tar;
  }
};

signed __CORE__() {
  tp n;
  Linear_Basis<Log_Hat_N> lb;
  re(n);
  while (n--) {
    tp x;
    re(x);
    lb.modify(x);
  }
  cout << lb.query();
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