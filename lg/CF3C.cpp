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
#define rs _Read_String()
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#define dputs(...)
#endif

using tp = long long;
tp _Read_Int();
char _Read_Char();
std::string _Read_String();
using namespace std;
constexpr bool __MTCS__ = 0;

namespace __SOL__ {
signed main() {
  tp X = 0, O = 0, WX = 0, WO = 0;
  array<char, 9> g;
  for (tp i = 0; i < 9; ++i) {
    if (g[i] = rc; g[i] == 'X') {
      ++X;
    } else if (g[i] == '0') {
      ++O;
    }
  }
  for (tp i = 0; i < 3; ++i) {
    if (g[3 * i] == g[3 * i + 1] && g[3 * i + 1] == g[3 * i + 2]) {
      WX |= g[3 * i] == 'X';
      WO |= g[3 * i] == '0';
    }
    if (g[i] == g[i + 3] && g[i + 3] == g[i + 6]) {
      WX |= g[i] == 'X';
      WO |= g[i] == '0';
    }
  }
  if ((g[0] == g[4] && g[4] == g[8]) || (g[2] == g[4] && g[4] == g[6])) {
    WX |= g[4] == 'X';
    WO |= g[4] == '0';
  }
  if ((WX && X != O + 1) || (WO && X != O) || (X != O + 1) && (X != O)) {
    puts("illegal");
  } else if (WX) {
    puts("the first player won");
  } else if (WO) {
    puts("the second player won");
  } else if (X + O == 9) {
    puts("draw");
  } else if (X == O) {
    puts("first");
  } else {
    puts("second");
  }
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
  __val = __c & 15;
  for (__c = getchar(); __c > 47 && __c < 58; __c = getchar()) {
    __val = __val * 10 + (__c & 15);
  }
  return __neg ? ~__val + 1 : __val;
}
char _Read_Char() {
  char __c = getchar();
  while (__c == 32 || __c == 10 || __c == 13) {
    __c = getchar();
  }
  return __c;
}
std::string _Read_String() {
  char __c = getchar();
  string __val;
  while (__c == 32 || __c == 10 || __c == 13) {
    __c = getchar();
  }
  do {
    __val.push_back(__c);
    __c = getchar();
  } while (__c != 32 && __c != 10 && __c != 13);
  return __val;
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