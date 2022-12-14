#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>
#define sv std::ranges::views::

using namespace std;
using tp = long long int;

vector<tp> f;

tp find(tp x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(tp u, tp v) {
  f[find(u)] = find(v);
}

signed main() {
  tp n;
  scanf("%lld", &n);
  vector<tp> v(n + 1), tar(n + 1, 0);
  f = vector<tp>(n + 1);
  for (tp j = 1; auto&& i : v | sv drop(1)) {
    scanf("%lld", &i);
    f[j] = j;
    ++j;
  }
  for (tp i = 2; i <= n; ++i) {
    for (tp j = 1; j < i; ++j) {
      if (v[i] * v[j] > 0) {
        tp rt = sqrt(v[i] * v[j]);
        for (auto&& x : {-1, 0, 1}) {
          if ((rt + x) * (rt + x) == v[i] * v[j]) {
            merge(i, j);
            break;
          }
        }
      }
    }
  }
  for (tp i = 1; i <= n; ++i) {
    tp cnt = 0;
    vector<bool> vis(n + 1, 1);
    for (tp j = i; j <= n; ++j) {
      if (v[j]) {
        if (vis[find(j)]) {
          vis[find(j)] = 0;
          ++cnt;
        }
        ++tar[cnt];
      } else {
        ++tar[cnt ? cnt : 1];
      }
    }
  }
  for (auto&& i : tar | sv drop(1)) {
    cout << i << ' ';
  }
  return EXIT_SUCCESS;
}

/*
 */

/*#################################################################
#.................................................................#
#.............#......#.......This.Code.Was.Created.By.RBTree......#
#............#.#....#.#..............Limiting-Factor..............#
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