// Please submit with C++20!
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
#define same(x, y) find(x) == c.find(y)
#ifdef ___RB_DEBUG___
std::map<uint64_t, uint64_t> __vis__;
#define dbg(...)                                                               \
  printf(                                                                      \
      ":>> At line '%llu', function '%s', come here in the %lluth time, '%s' " \
      "-> '",                                                                  \
      __LINE__, __FUNCTION__, ++__vis__[__LINE__], #__VA_ARGS__);              \
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

class Link_Cut_Tree {
  struct LCT_Node {
    bool color;
    tp f, ts, ch[2];
  };

  vector<LCT_Node> _lct;

  bool chd(tp x) { return _lct[_lct[x].f].ch[1] == x; }

  bool nroot(tp x) {
    return _lct[_lct[x].f].ch[0] == x || _lct[_lct[x].f].ch[1] == x;
  }

  void rotate(tp x) {
    bool z = chd(x);
    tp f = _lct[x].f, ff = _lct[f].f, y = _lct[x].ch[!z];
    if (nroot(f)) {
      _lct[ff].ch[chd(f)] = x;
    }
    if (_lct[_lct[_lct[x].ch[!z] = f].f = x].f = ff; _lct[f].ch[z] = y) {
      _lct[y].f = f;
    }
  }

  void Colorf(tp x) {
    if (x) {
      swap(_lct[x].ch[1], _lct[x].ch[0]);
      _lct[x].color ^= 1;
    }
  }

  void pushdown(tp x) {
    if (_lct[x].color) {
      Colorf(_lct[x].ch[0]);
      Colorf(_lct[x].ch[1]);
      _lct[x].color = 0;
    }
  }

  void Splay(tp x) {
    tp top = -1, y = x;
    for (_lct[++top].ts = y; nroot(y); _lct[++top].ts = y = _lct[y].f) {
    }
    while (~top) {
      pushdown(_lct[top--].ts);
    }
    for (; nroot(x); rotate(x)) {
      if (nroot(y = _lct[x].f)) {
        rotate(chd(x) != chd(y) ? x : y);
      }
    }
  }

  void access(tp x) {
    for (tp y = 0; x; x = _lct[x].f) {
      Splay(x);
      _lct[x].ch[1] = exchange(y, x);
    }
  }

 public:
  Link_Cut_Tree(tp n) { _lct.resize(n); }

  tp find(tp x) {
    access(x);
    for (Splay(x); _lct[x].ch[0]; x = _lct[x].ch[0]) {
      pushdown(x);
    }
    return x;
  }

  void link(tp x, tp y) {
    access(x);
    Splay(x);
    if (Colorf(x); find(y) != x) {
      _lct[x].f = y;
    }
  }

  void cut(tp x, tp y) {
    access(x);
    Splay(x);
    if (Colorf(x); find(y) == x && _lct[x].f == y && !_lct[x].ch[1]) {
      _lct[x].f = _lct[y].ch[0] = 0;
    }
  }
};

signed main() {
  tp n, k, tar = 0;
  scanf("%lld%lld", &n, &k);
  Link_Cut_Tree c(n * 3 + 3);
  while (k--) {
    tp t, x, y;
    scanf("%lld%lld%lld", &t, &x, &y);
    if (x > n || y > n) {
      ++tar;
      continue;
    }
    if (t == 1) {
      if (c.same(x, y + n) || c.same(x + n, y)) {
        ++tar;
      } else {
        c.link(x, y);
        c.link(x + n, y + n);
        c.link(x + 2 * n, y + 2 * n);
      }
    } else {
      if (c.same(x, y) || c.same(x, y + n)) {
        ++tar;
      } else {
        c.link(x, y + 2 * n);
        c.link(x + n, y);
        c.link(x + 2 * n, y + n);
      }
    }
  }
  printf("%lld
", tar);
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