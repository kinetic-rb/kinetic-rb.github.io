// Please submit with C++20!
#pragma GCC optimize("Ofast")
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <ranges>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#define sc(n) sv::iota(1) | sv::take(n)

using namespace std;
using tp = long long;
namespace sv = std::ranges::views;
constexpr tp _MOD_ = 1e9 + 9;

tp n;
vector<tp> tar, tmp, fib, fs;
vector<pair<tp, tp>> rm;

tp mod(tp v) {
  if (v < 0) {
    return v + _MOD_;
  } else if (v >= _MOD_) {
    v -= _MOD_;
  } else if (v >= _MOD_) {
    v -= _MOD_;
  }
  return v;
}

void maintain() {
  auto&& [a, b] = make_pair(tp(0), tp(0));
  vector<list<tp>> q(n + 1), p(n + 1);
  for (auto&& i : sv::iota(0) | sv::take(rm.size())) {
    q[rm[i].first].push_back(i);
    p[rm[i].second].push_back(i);
  }
  for (auto&& i : sc(n)) {
    tp c = a + b;
    a = b;
    b = c;
    tmp[i] = mod(tmp[i] + b);
    b = mod(b + q[i].size());
    tmp[i] = mod(tmp[i] + q[i].size());
    for (auto&& i : p[i]) {
      a = mod(a - fib[rm[i].second - rm[i].first]);
      b = mod(b - fib[rm[i].second - rm[i].first + 1]);
    }
    tar[i] = mod(tar[i - 1] + tmp[i]);
  }
  for (auto&& [i, j] : rm) {
    q[i].clear();
    p[j].clear();
  }
  rm.clear();
}

signed main() {
  bool c = 0;
  tp m, gmt;
  scanf("%lld%lld", &n, &m);
  tar = tmp = fib = fs = vector(n + 1, tp(0));
  tie(fib[1], fib[2], fs[1], fs[2], gmt) = make_tuple(1, 1, 1, 2, tp(sqrt(m)));
  for (tp i = 3; i <= n; ++i) {
    fs[i] = mod(fs[i - 1] + (fib[i] = mod(fib[i - 1] + fib[i - 2])));
  }
  for (tp i = 1; i <= n; ++i) {
    scanf("%lld", &tmp[i]);
    tar[i] = mod(tar[i - 1] + tmp[i]);
  }
  for (tp op, l, r; m--;) {
    scanf("%lld%lld%lld", &op, &l, &r);
    if (op == 1) {
      if (rm.emplace_back(l, r); rm.size() == gmt && c) {
        maintain();
        rm.reserve(gmt);
      }
    } else {
      tp sum = 0;
      c = 1;
      for (auto&& [_l, _r] : rm) {
        if (tp __l = max(l, _l), __r =  min(r, _r); __l <= __r) {
          sum = mod(sum + fs[__r - _l + 1] - fs[__l - _l]);
        }
      }
      printf("%lld
", mod(sum + tar[r] - tar[l - 1]));
    }
  }
  return 0;
}

/*#################################################################
#.................................................................#
#............................This.Code.Was.Created.By.RBTree......#
#.............#......#...............Limiting-Factor..............#
#............#.#....#.#.................Soul-Code.................#
#.............########............................................#
#............#........#..##############################...........#
#...........#..V....V......#..#........................#..#...#...#
#............#........#........###..###..........#..#.#.#..#
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