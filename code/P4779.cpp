// Please submit with C++14! It's best to use C++20 or higher version.
constexpr bool __MTCS__ = 0;  // Spectre (admin@rbtree.app)
#ifndef LOCAL                 // By rbtree (https://rbtree.app)
#pragma region HEAD           // DO OR DIE
#endif
#if OPTIMIZE
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#endif
#define ra (__QWQ_IO__::__Read_I(), la)
#define rc __QWQ_IO__::__Read_C()
#define rgc __QWQ_IO__::getchar()
#define rs __QWQ_IO__::__Read_S()
#define fls __QWQ_IO__::flush()
#define wq __QWQ_IO__::qaq,
#define se(exp) begin(exp), end(exp)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define qmx(exp1, exp2, exp3) exp1 = exp3(exp1, exp2)

typedef long long tp;
using namespace std;
void __Cored__(tp);
tp la;

namespace __QWQ_IO__ {
constexpr tp Size = 0x217217;
char in[Size], out[Size], stk[45];
char *s = in, *t = in, *S = out, *T = out + Size;
std::size_t top;
char getchar() {
  if (s == t)
    if (in == (t = (s = in) + fread(in, 1, Size, stdin))) return 10;
  return *s++;
}
void __Read_I() {
  bool f = 0;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) f = c == '-';
  la = c & 15;
  for (c = getchar(); c > 47 && c < 58; c = getchar()) la = la * 10 + (c & 15);
  la = f ? -la : la;
}
char __Read_C() {
  char c = getchar();
  while (c == 10 || c == 32) c = getchar();
  return c;
}
string __Read_S() {
  string s;
  for (char c = __Read_C(); c != 32 && c != 10 && c != 13; c = getchar())
    s.push_back(c);
  return s;
}
void flush() { return fwrite(out, 1, S - out, stdout), S = out, void(); }
void __Write(char c) {
  *S++ = c;
  if (S == T) flush();
}
void __Write(string s) {
  for (std::size_t i = 0; i < s.size(); ++i) __Write(s[i]);
}
void __Write(const char* s) {
  while (*s) __Write(*s++);
}
template <typename _Type>
void __Write(_Type x) {
  if (!x) return __Write('0');
  if (x < 0) __Write('-');
  for (x = abs(x); x; x /= 10) stk[++top] = x % 10;
  while (top) __Write(char(stk[top--] | 48));
}
template <typename _Type, typename... Other>
void __Write(_Type x, Other... y) {
  return __Write(x), __Write(y...);
}
struct QAQ {
  template <typename _Type>
  QAQ& operator,(_Type x) {
    return __Write(x), *this;
  }
} qaq;
}  // namespace __QWQ_IO__

signed main(/* >_< */) {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) __Cored__(++__NOW__);
  if (__QWQ_IO__::S == __QWQ_IO__::out) return 0;
  fwrite(__QWQ_IO__::out, 1, __QWQ_IO__::S - __QWQ_IO__::out, stdout);
  if (*--__QWQ_IO__::S != 10) putchar(10);
  return 0;
}

#ifndef LOCAL
#pragma endregion HEAD
#endif
#define OPTIMIZE 0;

////////////////////////////////////////////////////////////////////////////////

constexpr tp Hat_N = 1e5 + 3;

mt19937 rnd(20091001);

bool inq[Hat_N];
tp dist[Hat_N], q[Hat_N];
list<pair<tp, tp>> e[Hat_N];

void spfa(tp s) {
  tp l = 0, r = 0;
  memset(dist, 0x3f, sizeof dist);
  inq[s] = 1;
  dist[s] = 0;
  for (q[0] = s; l <= r;) {
    tp f = q[l];
    if (!(rnd() % ((r - l + 1 >> 4) + 1))) {
      stable_sort(q + l, q + r + 1, [](tp x, tp y) { return dist[x] < dist[y]; });
      f = q[l];
    }
    ++l;
    inq[f] = 0;
    for (auto&& t : e[f]) {
      if (dist[t.first] > dist[f] + t.second) {
        dist[t.first] = dist[f] + t.second;
        if (!inq[t.first]) {
          if (l) q[--l] = t.first;
          if (!l) q[++r] = t.first;
          inq[t.first] = 1;
        }
      }
    }
  }
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, m = ra, s = ra;
  while (m--) {
    tp u = ra, v = ra, w = ra;
    e[u].emplace_back(v, w);
  }
  spfa(s);
  for (tp i = 1; i <= n; ++i) wq dist[i], ' ';
}

//*/