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
#include <cstring>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 203, Hat_M = 5003;

tp s, t;
unordered_map<tp, tp> dep, head, to, next, mf;

void add(tp u, tp v, tp w) {
  static tp cnt = 1;
  to[++cnt] = v;
  mf[cnt] = w;
  ::next[cnt] = head[u];
  head[u] = cnt;
}

bool bfs() {
  list<tp> q;
  dep.clear();
  dep[s] = 1;
  for (q.push_back(s); q.size(); q.pop_front()) {
    for (tp i = head[q.front()]; i; i = ::next[i]) {
      if (!dep[to[i]] && mf[i]) {
        dep[to[i]] = dep[q.front()] + 1;
        q.push_back(to[i]);
      }
    }
  }
  return dep[t];
}

tp dfs(tp x, tp flow) {
  tp tar = 0;
  if (x == t) {
    return flow;
  }
  for (tp i = head[x]; i && flow; i = ::next[i]) {
    if (mf[i] && dep[to[i]] == dep[x] + 1) {
      tp tf = dfs(to[i], min(flow, mf[i]));
      mf[i] -= tf;
      mf[i ^ 1] += tf;
      flow -= tf;
      tar += tf;
    }
  }
  if (!tar) {
    dep[x] = 0;
  }
  return tar;
}

tp dinic() {
  tp tar = 0;
  while (bfs()) {
    tar += dfs(s, 0x7fffffffffffffff);
  }
  return tar;
}

signed main(/* >_< */) {
  tp n, m;
  cin >> n >> m >> s >> t;
  while (m--) {
    tp u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, 0);
  }
  cout << dinic();
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