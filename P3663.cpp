#include <iostream>
#include <set>
#include <string>
#include <vector>
#define rtp(__VALUE__) scanf("%lld", &__VALUE__)

using namespace std;
using tp = long long;
constexpr bool __MTCS__ = 0;
constexpr tp Hat_N = 103;

namespace {
template <typename _Typex>
string tpt(_Typex __value = 1, const string& __type = "%lld") {
  size_t __count = static_cast<size_t>(__value);
  string __target;
  __target.reserve(__count << 2ll);
  while (__count--) {
    __target += __type;
  }
  return __target;
}

template <typename... _Typey>
signed sf(const string& __input, _Typey&... __value) {
  return ::scanf(__input.c_str(), &__value...);
}
}  // namespace

namespace __SOL__ {
tp cnt, n;
tp dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
vector<tp> count(Hat_N * Hat_N, 0);
vector<vector<tp>> mz(Hat_N, vector<tp>(Hat_N));
vector<vector<bool>> vis(Hat_N, vector<bool>(Hat_N, 0));
vector<vector<set<pair<tp, tp>>>> disable(Hat_N,
                                          vector<set<pair<tp, tp>>>(Hat_N));

void dfs(tp x, tp y) {
  if (vis[x][y]) {
    return;
  }
  vis[x][y] = 1;
  mz[x][y] = cnt;
  for (auto&& i : dir) {
    tp dx = x + i[0], dy = y + i[1];
    if (~dx && dx < n && ~dy && dy < n &&
        !disable[x][y].count(make_pair(dx, dy))) {
      dfs(dx, dy);
    }
  }
}

void search() {
  for (tp i = 0; i < n; ++i) {
    for (tp j = 0; j < n; ++j) {
      if (!vis[i][j]) {
        ++cnt;
        dfs(i, j);
      }
    }
  }
}

signed main() {
  tp k, r, tar = 0;
  sf(tpt(3), n, k, r);
  while (r--) {
    tp a, b, c, d;
    sf(tpt(4), a, b, c, d);
    disable[--a][--b].emplace(--c, --d);
    disable[c][d].emplace(a, b);
  }
  search();
  while (k--) {
    tp x, y;
    sf(tpt(2), x, y);
    ++count[mz[x - 1][y - 1]];
  }
  for (tp i = 1; i < cnt; ++i) {
    for (tp j = i + 1; j <= cnt; ++j) {
      tar += count[i] * count[j];
    }
  }
  cout << tar;
  return 0;
}

signed PRE() {
  return 0;
}
}  // namespace __SOL__

signed main() {
  static tp __P__ = __SOL__::PRE(), __T__ = 1, __R__ = sf(tpt(__MTCS__), __T__);
  return __T__-- && (main() || __SOL__::main()) ? -1 : __P__;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//