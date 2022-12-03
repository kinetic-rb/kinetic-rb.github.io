// By rbtree - Koi Carp
// Please submit with C++14!
// :(     :\     :/     :)
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
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
#define iotop _Get_IO_Top()
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#define dputs(...)
#endif

using tp = long long;
tp _Read_Int();
char _Read_Char();
bool _Get_IO_Top();
std::string _Read_String();
using namespace std;
constexpr bool __MTCS__ = 0;
constexpr tp _BUF_SIZE_ = 2172179;

namespace __SOL__ {
constexpr tp Hat_N = 1e5 + 3;

array<tp, Hat_N * 4> a, b, c, lazy;

/*
 * a -> v_i
 * b -> i * v_i
 * c -> i * i * v_i
 */

tp ss(tp l, tp r) {
  return (r * (r + 1) * (2 * r + 1) - (l - 1) * l * (2 * l - 1)) / 6;
}

void pushdown(tp x, tp l, tp r) {
  tp mid = l + r >> 1;
  lazy[x << 1] += lazy[x];
  lazy[x << 1 | 1] += lazy[x];
  a[x << 1] += lazy[x] * (mid - l + 1);
  a[x << 1 | 1] += lazy[x] * (r - mid);
  b[x << 1] += lazy[x] * (l + mid) * (mid - l + 1) / 2;
  b[x << 1 | 1] += lazy[x] * (mid + 1 + r) * (r - mid) / 2;
  c[x << 1] += lazy[x] * ss(l, mid);
  c[x << 1 | 1] += lazy[x] * ss(mid + 1, r);
  lazy[x] = 0;
}

void modify(tp x, tp ml, tp mr, tp l, tp r, tp k) {
  if (ml <= l && r <= mr) {
    a[x] += k * (r - l + 1);
    b[x] += k * (l + r) * (r - l + 1) / 2;
    c[x] += k * ss(l, r);
    lazy[x] += k;
  } else {
    tp mid = l + r >> 1;
    pushdown(x, l, r);
    if (ml <= mid) {
      modify(x << 1, ml, mr, l, mid, k);
    }
    if (mid < mr) {
      modify(x << 1 | 1, ml, mr, mid + 1, r, k);
    }
    a[x] = a[x << 1] + a[x << 1 | 1];
    b[x] = b[x << 1] + b[x << 1 | 1];
    c[x] = c[x << 1] + c[x << 1 | 1];
  }
}

tp query(tp x, tp ml, tp mr, tp l, tp r, tp type) {
  if (ml <= l && r <= mr) {
    return type == 1 ? a[x] : type == 2 ? b[x] : c[x];
  } else {
    tp mid = l + r >> 1, sum = 0;
    pushdown(x, l, r);
    if (ml <= mid) {
      sum += query(x << 1, ml, mr, l, mid, type);
    }
    if (mid < mr) {
      sum += query(x << 1 | 1, ml, mr, mid + 1, r, type);
    }
    return sum;
  }
}

signed main([[maybe_unused]] size_t __CASE__) {
  tp n = ra, m = ra;
  while (m--) {
    char op = rc;
    tp l = ra, r = ra;
    if (op == 'C') {
      modify(1, l, r - 1, 1, n - 1, ra);
    } else {
      tp a = (r - l * r) * query(1, l, r - 1, 1, n - 1, 1) +
             (r + l - 1) * query(1, l, r - 1, 1, n - 1, 2) -
             query(1, l, r - 1, 1, n - 1, 3),
         b = (r - l + 1) * (r - l) >> 1;
      printf("%lld/%lld
", a / __gcd(a, b), b / __gcd(a, b));
    }
  }
  return 0;
}
}  // namespace __SOL__

signed main() {
  tp __MTCS__ = ::__MTCS__ ? ra : 1;
  for (tp __i = 1; __i <= __MTCS__; ++__i) {
    __SOL__::main(__i);
  }
  return EXIT_SUCCESS;
}

namespace _READ_RAW_ {
array<char, _BUF_SIZE_> _BUF_;
array<char, _BUF_SIZE_>::iterator __Cur, __End = __Cur + 1;

char _Rd() {
  if (++__Cur == __End) {
    __Cur = _BUF_.begin();
    __End = __Cur + fread(_BUF_.begin(), 1, _BUF_SIZE_, stdin);
  }
  return *__Cur;
}
}  // namespace _READ_RAW_

bool _Get_IO_Top() {
  if (_READ_RAW_::__Cur + 1 == _READ_RAW_::__End) {
    _READ_RAW_::__Cur = _READ_RAW_::_BUF_.begin();
    _READ_RAW_::__End = _READ_RAW_::__Cur +
                        fread(_READ_RAW_::_BUF_.begin(), 1, _BUF_SIZE_, stdin);
    return _READ_RAW_::__Cur-- != _READ_RAW_::__End;
  }
  return 1;
}
tp _Read_Int() {
  bool __neg(0);
  char __c(_READ_RAW_::_Rd());
  tp __val(0);
  for (; __c < 48 || __c > 57; __c = _READ_RAW_::_Rd()) {
    __neg = __c == 45;
  }
  __val = __c & 15;
  for (__c = _READ_RAW_::_Rd(); __c > 47 && __c < 58; __c = _READ_RAW_::_Rd()) {
    __val = __val * 10 + (__c & 15);
  }
  return __neg ? ~__val + 1 : __val;
}
char _Read_Char() {
  char __c = _READ_RAW_::_Rd();
  while (__c == 32 || __c == 10 || __c == 13) {
    __c = _READ_RAW_::_Rd();
  }
  return __c;
}
std::string _Read_String() {
  char __c = _READ_RAW_::_Rd();
  string __val;
  while (__c == 32 || __c == 10 || __c == 13) {
    __c = _READ_RAW_::_Rd();
  }
  do {
    __val.push_back(__c);
    __c = _READ_RAW_::_Rd();
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