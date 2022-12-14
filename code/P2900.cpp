#include <algorithm>
#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 5e4 + 3;

tp f[Hat_N];
struct Rs {
  tp w, h;

  Rs() = default;
  bool operator<(const Rs& comp) const {
    if (w != comp.w) {
      return w > comp.w;
    }
    return h > comp.h;
  }
  bool operator==(const Rs& comp) const { return h > comp.h; }
} s[Hat_N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    cin >> s[i].w >> s[i].h;
  }
  stable_sort(s + 1, s + n + 1);
  n = unique(s + 1, s + n + 1) - s - 1;
  for (tp i = 1; i <= n; ++i) {
    f[i] = 0x7fffffffffffffff;
    for (tp j = 1; j <= i; ++j) {
      f[i] = min(f[i], f[j - 1] + s[i].h * s[j].w);
    }
  }
  cout << f[n];
  return 0;
}

/*#################################################################
#.................................................................#
#.............#......#............Created.By.RBTree...............#
#............#.#....#.#........... Limiting-Factor................#
#.............########............................................#
#............#........#..##############################...........#
#...........#..V........V..#..#........................#..#...#...#
#............#........#....#..........###..###..........#..#.#.#..#
#............#..X##X..#..#............#....#.#...........#..#...#.#
#...........#...N##N...#..#...........###..###..........#.........#
#.......MOO..#........#....#.#.#.#...................#.#..........#
#.............########.....#.#.#.##############.#.#..#.#..........#
#..........................#.#.#.#.............#.#.#.#.#..........#
#......#########...........#.#.#.#.................#.#.#..........#
#.....#.........#..........#.#.#.#.................#.#.#..........#
#.#.#.#G#R#A#S#S#.#.#......#.#.#.#.................#.#.#..........#
#.###################......#.#.#.#.................#.#.#..........#
#...........................#.#.#...................#.#...........#
#.................................................................#
#################################################################*/