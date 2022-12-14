/*
\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000 \u2227\uff3f\u2227
\u3000\u3000\u3000\u3000\u3000 \u2227\uff3f\u2227 \u3000\uff08\u00b4<_\uff40 \uff09\u3000 Welcome to My Coding Space ^_^
\u3000\u3000\u3000\u3000 \uff08 \u00b4_\u309d`\uff09\u3000/\u3000 \u2312i
\u3000\u3000\u3000\u3000\uff0f\u3000\u3000\u3000\uff3c\u3000 \u3000  |\u3000|
\u3000\u3000\u3000 /\u3000\u3000 /\uffe3\uffe3\uffe3\uffe3/\u3000|\u3000|
\u3000 \uff3f_(__\uff86\u3064/\u3000\u3000 \u3000 / .| .|\uff3f\uff3f\uff3f\uff3f
\u3000 \u3000\u3000\u3000\uff3c/\uff3f\uff3f\uff3f\uff3f/\u3000\uff08u\u3000\u2283
*/

#include <iostream>
#include <vector>

using namespace std;
using tp = long long;
constexpr tp Hat_S = 503, _MOD_ = 1e6 + 7;

vector<vector<tp>> _get_() {
  vector<vector<tp>> v(Hat_S, vector<tp>(Hat_S, 0));
  v[0][0] = 1;
  for (tp i = 0; i < Hat_S; ++i) {
    v[i][0] = v[i][i] = 1;
    for (tp j = 1; j < i; ++j) {
      v[i][j] = (v[i - 1][j] + v[i - 1][j - 1]) % _MOD_;
    }
  }
  return v;
}

tp calc(tp n, tp m) {
  static vector<vector<tp>> c = _get_();
  return c[n][m];
}

signed Core(tp t) {
  tp n, m, k, tar = 0;
  scanf("%lld%lld%lld", &n, &m, &k);
  for (tp s = 0; s < 16; ++s) {
    tp v =
        calc((n - (s & 1) - bool(s & 2)) * (m - bool(s & 4) - bool(s & 8)), k);
    v *= ((s & 1) + bool(s & 2) + bool(s & 4) + bool(s & 8) & 1 ? -1 : 1);
    tar = (tar + v + _MOD_) % _MOD_;
  }
  cout << "Case " << t << ": " << tar << '\n';
  return 0;
}

signed main() {
  tp t;
  scanf("%lld", &t);
  for (tp i = 1; i <= t; ++i) {
    Core(i);
  }
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