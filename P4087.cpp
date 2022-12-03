#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rtp(__VALUE__) scanf("%lld", &__VALUE__)

namespace {
template <typename _Typex>
std::string tpt(_Typex __value = 1, const std::string& __type = "%lld") {
  size_t __count = static_cast<size_t>(__value);
  std::string __target;
  __target.reserve(__count * __type.size());
  while (__count--) {
    __target += __type;
  }
  return __target;
}

template <typename... _Typex>
signed sf(const std::string& __input, _Typex&... __value) {
  return ::scanf(__input.c_str(), &__value...);
}
}  // namespace

using namespace std;
using tp = long long;
constexpr bool __MTCS__ = 0;

namespace __SOL__ {
struct data_t {
  tp time, id, value;

  data_t() = default;
  data_t(tp _time, tp _id, tp _value) : time(_time), id(_id), value(_value) {}

  bool operator<(const data_t& comp) const { return time < comp.time; }
};

signed main() {
  tp n, g, tar = 0;
  map<tp, tp> cow;
  map<tp, tp, greater<tp>> cnt;
  sf(tpt(2), n, g);
  vector<data_t> data(n);
  for (auto&& i : data) {
    sf(tpt(3), i.time, i.id, i.value);
  }
  stable_sort(data.begin(), data.end());
  cnt[0] = n + 1;
  for (auto&& d : data) {
    bool t = cow[d.id] == cnt.begin()->first;
    tp before = --cnt[cow[d.id]];
    if (!before) {
      cnt.erase(cow[d.id]);
    }
    cow[d.id] += d.value;
    ++cnt[cow[d.id]];
    if (t) {
      if (cow[d.id] != cnt.begin()->first || before || cnt[cow[d.id]] != 1) {
        ++tar;
      }
    } else if (cow[d.id] == cnt.begin()->first) {
      ++tar;
    }
  }
  cout << tar << '\n';
  return 0;
}

signed PRE() {
  return 0;
}
}  // namespace __SOL__

signed main() {
  static tp __P__ = __SOL__::PRE(), __T__ = __MTCS__ ? (rtp(__T__), __T__) : 1;
  return __T__-- && (main() || __SOL__::main()) ? -1 : __P__;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//