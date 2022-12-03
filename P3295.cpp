// Please submit with C++20!
#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
#define sc(n) sv::iota(1) | sv::take(n)
#ifdef ___RB_DEBUG___
#define dbg(...)                                                   \
  printf(":>> At line '%lld', function '%s', '%s' -> '", __LINE__, \
         __FUNCTION__, #__VA_ARGS__);                              \
  _dbg(__VA_ARGS__)
#define dputs(...) printf(__VA_ARGS__)
template <typename _Type>
void _dbg(const _Type& _cur) {
  std::cout << _cur << "' <<:
";
}
template <typename _Type, typename... _Other>
void _dbg(const _Type& _cur, const _Other&... _other) {
  std::cout << _cur << ", ";
  _dbg(_other...);
}
#else
#define dbg(...)
#define dputs(...)
#endif

using namespace std;
using tp = long long;
namespace sv = std::ranges::views;
constexpr tp LG_N = 20, _MOD_ = 1e9 + 7;

vector<vector<tp>> f;

tp find(tp x, tp k) {
  return f[x][k] == x ? x : f[x][k] = find(f[x][k], k);
}

void merge(tp x, tp y, tp k) {
  if (find(x, k) != find(y, k)) {
    f[f[x][k]][k] = f[y][k];
  }
}

signed main() {
  tp n, m, tar = 9, cnt = 0;
  scanf("%lld%lld", &n, &m);
  f = vector<vector<tp>>(n + 1, vector<tp>(LG_N + 1));
  for (auto&& i : sc(n)) {
    for (auto&& j : f[i]) {
      j = i;
    }
  }
  for (tp a1, a2, b1, b2; m--;) {
    scanf("%lld%lld%lld%lld", &a1, &a2, &b1, &b2);
    for (auto&& i : sv::iota(0) | sv::take(LG_N) | sv::reverse) {
      if (a1 + (1ll << i) - 1 <= a2) {
        merge(a1, b1, i);
        a1 += 1ll << i;
        b1 += 1ll << i;
      }
    }
  }
  for (auto&& j : sc(LG_N) | sv::reverse) {
    for (tp i = 1; i + (1ll << j) - 1 <= n; ++i) {
      merge(i, find(i, j), j - 1);
      merge(i + (1ll << j - 1), f[i][j] + (1ll << j - 1), j - 1);
    }
  }
  for (tp i = 1; i <= n; ++i) {
    cnt += find(i, 0) == i;
  }
  while (--cnt) {
    tar = (tar * 10) % _MOD_;
  }
  cout << tar << '\n';
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