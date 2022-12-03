#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

using namespace std;
using tp = int;
using igt = __m256i;
using qgt = __m512i;
constexpr tp Hat_N = 1e7 + 3;

tp v[Hat_N], ll[Hat_N], rl[Hat_N];

template <typename Typex>
void read(Typex&& __v) {
  bool f = 0;
  static char *__buf = (char*)malloc(1048575), *__s = __buf,
              *__e = __buf + fread(__buf, 1, 1048575, stdin);
  struct __Fetch {
    char operator()() {
      if (__s == __e) {
        __s = __buf;
        __e = __s + fread(__buf, 1, 1048575, stdin);
      }
      return *__s++;
    }
  } __getchar;
  char __ch(__getchar());
  while (__ch < 48 || __ch > 57) {
    f |= __ch == 45;
    __ch = __getchar();
  }
  __v = -(__ch & 15);
  for (__ch = __getchar(); __ch > 47 && __ch < 58; __ch = __getchar()) {
    __v = __v * 10 - (__ch & 15);
  }
  if (!f) {
    __v = -__v;
  }
}

signed main() {
  tp n;
  long long l = 0, r = 0;
  list<tp> s;
  read(n);
  for (tp i = 1; i <= n; ++i) {
    read(v[i]);
  }
  for (tp i = 1; i <= n; ++i) {
    tp rec;
    bool pd = 0;
    while (s.size() && v[s.back()] > v[i]) {
      pd = 1;
      rec = s.back();
      s.pop_back();
    }
    if (s.size()) {
      rl[s.back()] = i;
    }
    if (pd) {
      ll[i] = rec;
    }
    s.push_back(i);
  }
  for (tp i = 1; i <= n; ++i) {
    l ^= 1ll * i * (ll[i] + 1);
  }
  for (tp i = 1; i <= n; ++i) {
    r ^= 1ll * i * (rl[i] + 1);
  }
  cout << l << ' ' << r;
  return 0;
}