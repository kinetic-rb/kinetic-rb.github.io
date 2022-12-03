// By rbtree - Koi Carp
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#define ra _Read_Int()
#define rc _Read_Char()
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#define dputs(...)
#endif

using tp = long long;
tp _Read_Int();
char _Read_Char();
using namespace std;
constexpr bool __MTCS__ = 0;
constexpr tp Hat_N = 23;

namespace __SOL__ {
tp n, m;
array<array<char, Hat_N>, Hat_N> a;

bool check(tp x, tp y) {
  set<string> app;
  for (tp i = 1; i <= n; i += x) {
    for (tp j = 1; j <= m; j += y) {
      string s;
      for (tp u = i, endu = i + x; u < endu; ++u) {
        for (tp v = j, endv = j + y; v < endv; ++v) {
          s.push_back(a[u][v]);
        }
      }
      if (app.count(s)) {
        return 0;
      }
      app.insert(s);
      reverse(s.begin(), s.end());
      app.insert(s);
      if (x == y) {
        s.clear();
        for (tp u = j, endu = j + y; u < endu; ++u) {
          for (tp v = i + x - 1; v >= i; --v) {
            s.push_back(a[v][u]);
          }
        }
        app.insert(s);
        reverse(s.begin(), s.end());
        app.insert(s);
      }
    }
  }
  return 1;
}

signed main() {
  tp cnt = 0, minx = -1u >> 2, miny = -1u >> 2;
  n = ra;
  m = ra;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= m; ++j) {
      a[i][j] = rc;
    }
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= m; ++j) {
      if (!(n % i) && !(m % j) && check(i, j)) {
        if (++cnt; i * j < minx * miny) {
          minx = i;
          miny = j;
        }
      }
    }
  }
  printf("%lld
%lld %lld
", cnt, minx, miny);
  return 0;
}
}  // namespace __SOL__

signed main() {
  tp __MTCS__ = ::__MTCS__ ? ra : 1;
  while (__MTCS__--) {
    __SOL__::main();
  }
  return EXIT_SUCCESS;
}

tp _Read_Int() {
  bool __neg(0);
  char __c(getchar());
  tp __val(0);
  for (; __c < 48 || __c > 57; __c = getchar()) {
    __neg = __c == 45;
  }
  for (; __c > 47 && __c < 58; __c = getchar()) {
    __val = __val * 10 + (__c & 15);
  }
  return __neg ? ~__val + 1 : __val;
}
char _Read_Char() {
  char c = getchar();
  while (c == 32 || c == 10 || c == 13) {
    c = getchar();
  }
  return c;
}

/*#################################################################
#.................................................................#
#............................This.Code.Was.Created.By.RBTree......#
#.............#......#...............Limiting-Factor..............#
#............#.#....#.#.................Soul-Code.................#
#.............########............................................#
#............#........#..##############################...........#
#...........#..V....V......#..#........................#..#...#...#
#............#........#....#..........###..###..........#..#.#.#..#
#............#..X##X..#..#............#....#.#...........#..#...#.#
#...........#...N##N...#..#...........###..###..........#.........#
#.......MOE..#..@.....#....#.#.#.#...................#.#..........#
#.............########.....#.#.#.##############.#.#..#.#..........#
#..........................#.#.#.#.............#.#.#.#.#..........#
#......#########...........#.#.#.#.................#.#.#..........#
#.....#.........#..........#.#.#.#.................#.#.#..........#
#.#.#.#G#R#A#S#S#.#.#......#.#.#.#.................#.#.#..........#
#.###################......#.#.#.#.................#.#.#..........#
#...........................#.#.#...................#.#...........#
#.................................................................#
#################################################################*/