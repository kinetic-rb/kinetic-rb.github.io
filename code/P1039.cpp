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

bool f[23], d[7], nd[7], gt[23], ng[23];

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, m = ra, p = ra;
  map<string, tp> id;
  map<tp, string> name;
  map<tp, vector<pair<tp, tp>>> g;
  set<pair<tp, string>> day({{0, "Monday"},
                             {1, "Tuesday"},
                             {2, "Wednesday"},
                             {3, "Thursday"},
                             {4, "Saturday"},
                             {5, "Friday"},
                             {6, "Sunday"}});
  set<tp> gs;
  for (tp i = 1; i <= n; ++i) {
    string s = rs;
    id[s] = i;
    name[i] = s;
  }
  for (tp i = 1; i <= p; ++i) {
    string s = rs, t;
    s.pop_back();
    for (char c; c = rgc, c != '\n' && c != '\r'; t.push_back(c)) {
    }
    if (t == "I am guilty.")
      g[id[s]].emplace_back(0, id[s]);
    else if (t == "I am not guilty.")
      g[id[s]].emplace_back(1, id[s]);
    else {
      for (tp i = 1; i <= n; ++i) {
        if (t == name[i] + " is guilty.") g[id[s]].emplace_back(0, i);
        if (t == name[i] + " is not guilty.") g[id[s]].emplace_back(1, i);
      }
      for (auto&& i : day) {
        if (t == "Today is " + i.second + '.')
          g[id[s]].emplace_back(2, i.first);
      }
    }
  }
  if (n > 1) {
    bool f = 0;
    for (tp i = 1; i <= n; ++i) f |= g[i].size();
    if (!f) {
      wq "Cannot Determine";
      return;
    }
  }
  for (tp i = (1ll << n) - 1; ~i; --i) {
    if (__builtin_popcount(i) == m) {
      bool c = 1;
      for (tp j = 0; j < n; ++j) f[j + 1] = i >> j & 1;
      memset(d, 0, sizeof d);
      memset(nd, 0, sizeof nd);
      memset(gt, 0, sizeof gt);
      memset(ng, 0, sizeof ng);
      for (tp i = 1; i <= n; ++i) {
        for (auto&& j : g[i]) {
          if (f[i]) {
            if (!j.first) ng[j.second] = 1;
            if (j.first == 1) gt[j.second] = 1;
            if (j.first == 2) nd[j.second] = 1;
          } else {
            if (!j.first) gt[j.second] = 1;
            if (j.first == 1) ng[j.second] = 1;
            if (j.first == 2) d[j.second] = 1;
          }
        }
      }
      if (count_if(ng + 1, ng + n + 1, [](bool x) { return !x; }) == 1 &&
          !count_if(gt + 1, gt + n + 1, [](bool x) { return x; })) {
        for (tp i = 1; i <= n; ++i) {
          if (!ng[i]) gt[i] = 1;
        }
      }
      if (count_if(d, d + 7, [](bool x) { return x; }) > 1 ||
          count_if(gt + 1, gt + n + 1, [](bool x) { return x; }) != 1)
        c = 0;
      else {
        for (tp i = 0; i < 7; ++i) {
          if (d[i] && nd[i]) c = 0;
        }
        for (tp i = 1; i <= n; ++i) {
          if (gt[i] && ng[i]) c = 0;
        }
      }
      if (c) {
        for (tp i = 1; i <= n; ++i) {
          if (gt[i]) gs.insert(i);
        }
      }
    }
  }
  if (gs.size() > 1)
    wq "Cannot Determine";
  else if (gs.size() == 1)
    wq name[*gs.begin()];
  else
    wq "Impossible";
}

//*/