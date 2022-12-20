#include <cstdint>
#include <iostream>

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
constexpr bool __TEST_CASES__ = 1;
constexpr tp Hat_N = 2e5 + 3;

tp v[Hat_N];

signed __PRE__() {
  return 0;
}

signed __CORE__() {
  tp n, k;
  cin >> n >> k;
  for (tp i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (tp j = 30; ~j; --j) {
    tp f = 0;
    for (tp i = 1; i <= n; ++i) {
      if (~(v[i] >> j) & 1) {
        ++f;
      }
    }
    if (f <= k) {
      for (tp i = 1; i <= n; ++i) {
        v[i] |= 1 << j;
      }
      k -= f;
    }
  }
  for (tp i = 2; i <= n; ++i) {
    v[1] &= v[i];
  }
  cout << v[1] << '\n';
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