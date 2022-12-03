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

constexpr tp Hat_N = 5003;

tp s[Hat_N], dist[Hat_N][Hat_N], best[Hat_N], cest[Hat_N], dest[Hat_N],
    eest[Hat_N], bid[Hat_N], cid[Hat_N], did[Hat_N], eid[Hat_N];
vector<tp> e[Hat_N];

void bfs(tp s) {
  deque<tp> q;
  dist[s][s] = 1;
  for (q.push_back(s); q.size(); q.pop_front()) {
    for (auto&& i : e[q.front()]) {
      if (dist[s][i] == **dist) {
        dist[s][i] = dist[s][q.front()] + 1;
        q.push_back(i);
      }
    }
  }
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, m = ra, l = ra + 2, MAX = 0;
  memset(dist, 0x3f, sizeof dist);
  for (tp i = 2; i <= n; ++i) s[i] = ra;
  while (m--) {
    tp u = ra, v = ra;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (tp i = 1; i <= n; ++i) bfs(i);
  for (tp i = 1; i <= n; ++i)
    best[i] = cest[i] = dest[i] = eest[i] = -(-1ull >> 1);
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 2; j <= n; ++j) {
      if (i != j && dist[i][j] <= l && dist[j][1] <= l) {
        if (s[j] >= best[i]) {
          eest[i] = dest[i];
          dest[i] = cest[i];
          cest[i] = best[i];
          best[i] = s[j];
          eid[i] = did[i];
          did[i] = cid[i];
          cid[i] = bid[i];
          bid[i] = j;
        } else if (s[j] >= cest[i]) {
          eest[i] = dest[i];
          dest[i] = cest[i];
          cest[i] = s[j];
          eid[i] = did[i];
          did[i] = cid[i];
          cid[i] = j;
        } else if (s[j] >= dest[i]) {
          eest[i] = dest[i];
          dest[i] = s[j];
          eid[i] = did[i];
          did[i] = j;
        } else if (s[j] >= eest[i]) {
          eest[i] = s[j];
          eid[i] = j;
        }
      }
    }
  }
  for (tp j = 2; j <= n; ++j) {
    for (tp k = 2; k <= n; ++k) {
      if (k != j && dist[j][k] <= l) {
        tp a1 = best[j], a2 = cest[j], a3 = dest[j], a4 = eest[j], b1 = best[k],
           b2 = cest[k], b3 = dest[k], b4 = eest[k], x1, x2, y1, y2, z1, z2;
        if (bid[j] == j || bid[j] == k) {
          if (cid[j] == j || cid[j] == k) {
            x1 = a3;
            z1 = did[j];
            x2 = a4;
          } else {
            x1 = a2;
            z1 = cid[j];
            x2 = did[j] == j || did[j] == k ? a4 : a3;
          }
        } else {
          x1 = a1;
          z1 = bid[j];
          x2 = cid[j] == j || cid[j] == k ? did[j] == j || did[j] == k ? a4 : a3
                                          : a2;
        }
        if (bid[k] == j || bid[k] == k) {
          if (cid[k] == j || cid[k] == k) {
            y1 = b3;
            z2 = did[k];
            y2 = b4;
          } else {
            y1 = b2;
            z2 = cid[k];
            y2 = did[k] == j || did[k] == k ? b4 : b3;
          }
        } else {
          y1 = b1;
          z2 = bid[k];
          y2 = cid[k] == j || cid[k] == k ? did[k] == j || did[k] == k ? b4 : b3
                                          : b2;
        }
        if (z1 != z2) {
          if (x1 >= 0 && y1 >= 0) MAX = max(MAX, x1 + s[j] + s[k] + y1);
        } else {
          if (x1 >= 0 && y2 >= 0) MAX = max(MAX, x1 + s[j] + s[k] + y2);
          if (x2 >= 0 && y1 >= 0) MAX = max(MAX, x2 + s[j] + s[k] + y1);
        }
      }
    }
  }
  wq MAX;
}

//*/