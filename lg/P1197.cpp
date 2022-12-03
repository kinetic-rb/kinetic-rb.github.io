#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <tuple>
#include <vector>
#define sc(n) sv::iota(1) | sv::take(n)

using namespace std;
using tp = long long int;
namespace sv = std::ranges::views;

tp n;
map<tp, tp> f;

struct icecream {
  tp x, y, id;

  bool operator<(const icecream& comp) const { return id < comp.id; }
};

tp find(tp x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(tp x, tp y) {
  if (tie(x, y) = make_pair(find(x), find(y)); x != y) {
    --n;
    f[x] = y;
  }
}

signed main() {
  tp m;
  scanf("%lld%lld", &n, &m);
  vector<tp> d(n + 1), tar;
  vector<icecream> e(m);
  for (auto&& i : sc(n)) {
    f[i] = i;
  }
  for (auto&& [i, j, k] : e) {
    scanf("%lld%lld", &i, &j);
  }
  scanf("%lld", &m);
  tar = vector<tp>(m + 1);
  for (auto&& i : sc(m)) {
    tp x;
    scanf("%lld", &x);
    d[x] = m - i + 1;
  }
  for (auto&& [i, j, k] : e) {
    k = max(d[i], d[j]);
  }
  stable_sort(e.begin(), e.end());
  for (tp j = 0; auto&& i : sv::iota(0) | sv::take(m + 1)) {
    for (; e[j].id == i; ++j) {
      merge(e[j].x, e[j].y);
    }
    tar[i] = n - m + i;
  }
  for (auto&& i : tar | sv::reverse) {
    cout << i << '\n';
  }
  return EXIT_SUCCESS;
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