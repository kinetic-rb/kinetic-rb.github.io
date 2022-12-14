/*
\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000 \u2227\uff3f\u2227
\u3000\u3000\u3000\u3000\u3000 \u2227\uff3f\u2227 \u3000\uff08\u00b4<_\uff40 \uff09\u3000 Welcome to My Coding Space ^_^
\u3000\u3000\u3000\u3000 \uff08 \u00b4_\u309d`\uff09\u3000/\u3000 \u2312i
\u3000\u3000\u3000\u3000\uff0f\u3000\u3000\u3000\uff3c\u3000 \u3000  |\u3000|
\u3000\u3000\u3000 /\u3000\u3000 /\uffe3\uffe3\uffe3\uffe3/\u3000|\u3000|
\u3000 \uff3f_(__\uff86\u3064/\u3000\u3000 \u3000 / .| .|\uff3f\uff3f\uff3f\uff3f
\u3000 \u3000\u3000\u3000\uff3c/\uff3f\uff3f\uff3f\uff3f/\u3000\uff08u\u3000\u2283
*/

#include <cstdint>
#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 1e5 + 3;

tp v[Hat_N];

template <typename Typex>
intmax_t fs(intmax_t loc, intmax_t r, Typex Checker) {
  if (loc >= r) {
    return loc;
  }
  for (intmax_t popple = r - loc; popple; popple >>= 1) {
    intmax_t now = loc + popple;
    if (now <= r && Checker(now)) {
      loc = now;
    }
  }
  return loc;
}

signed main() {
  tp n, k, Max = 0;
  cin >> n >> k;
  for (tp i = 0; i < n; ++i) {
    cin >> v[i];
    Max = max(Max, v[i] * v[i]);
  }
  cout << fs(0, 1ll << 60, [&](tp m) -> bool {
            tp days = 0;
            for (tp i = 0; i < n; ++days) {
              tp sum = 0;
              if (v[i] * v[i] > m) {
                return 1;
              }
              while (sum + v[i] * v[i] <= m && i < n) {
                sum += v[i] * v[i];
                ++i;
              }
            }
            return days > k;
          }) + 1;
  return 0;
}

/*#################################################################
#.................................................................#
#.............#......#............Created.By.RBTree...............#
#............#.#....#.#........... Limiting-Factor................#
#.............########............................................#
#............#........#..##############################...........#
#...........#..V....V......#..#........................#..#...#...#
#............#........#....#..........###..###..........#..#.#.#..#
#............#..X##X..#..#............#....#.#...........#..#...#.#
#...........#...N##N...#..#...........###..###..........#.........#
#.......MOO..#..@.....#....#.#.#.#...................#.#..........#
#.............########.....#.#.#.##############.#.#..#.#..........#
#..........................#.#.#.#.............#.#.#.#.#..........#
#......#########...........#.#.#.#.................#.#.#..........#
#.....#.........#..........#.#.#.#.................#.#.#..........#
#.#.#.#G#R#A#S#S#.#.#......#.#.#.#.................#.#.#..........#
#.###################......#.#.#.#.................#.#.#..........#
#...........................#.#.#...................#.#...........#
#.................................................................#
#################################################################*/