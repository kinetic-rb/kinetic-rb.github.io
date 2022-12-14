#include <iostream>
#include <list>
#include <vector>

using namespace std;
using tp = long long int;
constexpr tp dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};

tp n;
vector<vector<bool>> mp(1001, vector<bool>(1001, 0)),
    qed(1001, vector<bool>(1001, 0));

struct Loc {
  tp x, y, step;

  Loc() = default;
  Loc(tp _x, tp _y, tp _step) : x(_x), y(_y), step(_step) {}
};

void record(tp x, tp y, tp step, list<Loc>& q) {
  qed[x][y] = 1;
  q.emplace_back(x, y, step + mp[x][y]);
}

tp bfs(tp sx, tp sy) {
  tp MIN = -1ull >> 2;
  list<Loc> q;
  for (record(sx, sy, 0, q); q.size(); q.pop_front()) {
    for (auto&& p : dir) {
      tp px = q.front().x + p[0], py = q.front().y + p[1];
      if (px < 1 || py < 1 || px > 1000 || py > 1000) {
        MIN = min(MIN, q.front().step);
        continue;
      }
      if (!qed[px][py]) {
        record(px, py, q.front().step, q);
      }
    }
  }
  return MIN;
}

signed main() {
  tp x, y;
  scanf("%lld%lld%lld", &n, &x, &y);
  while (n--) {
    tp _x, _y;
    scanf("%lld%lld", &_x, &_y);
    mp[_x][_y] = 1;
  }
  cout << bfs(x, y) << '\n';
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
