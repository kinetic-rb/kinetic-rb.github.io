#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace __DEF_LAND__ {
using namespace std;
using tp = long long;
constexpr bool __MTCS__ = 0;
constexpr char __RV__[] = "%lld";
}  // namespace __DEF_LAND__
namespace {
using namespace __DEF_LAND__;
namespace __SOLUTION_LAND__ {
signed main();
signed PRE();
}  // namespace __SOLUTION_LAND__

template <typename _Type>
bool rv(_Type& __value) {
  return ~scanf(__RV__, &__value);
}

template <typename _Typex, typename... _Typey>
bool rv(_Typex& __value, _Typey&... __other) {
  return rv(__value) ? rv(__other...) : 0;
}

tp rv() {
  tp __value;
  rv(__value);
  return __value;
}
}  // namespace
signed main() {
  static signed __P__ = __SOLUTION_LAND__::PRE(), __T__ = __MTCS__ ? rv() : 1;
  return __T__-- && (main() || __SOLUTION_LAND__::main()) ? -1 : __P__;
}

/** @note The following is the main part. **/

/** @note The following is the core of the main part. **/

signed __SOLUTION_LAND__::main() {
  tp n = rv(), cost = 0, MIN = -1ull / 2;
  vector<pair<tp, tp>> loc(1, make_pair(MIN, 0));
  for (tp a, b; n--;) {
    rv(a, b);
    cost += abs(a - b);
    if (abs(a - b) > abs(a)) {
      loc.emplace_back(b - abs(a - b) + abs(a), -1);
      loc.emplace_back(b, 2);
      loc.emplace_back(b + abs(a - b) - abs(a), -1);
    }
  }
  stable_sort(loc.begin() + 1, loc.end());
  for (auto it = loc.begin(); ++it != loc.end(); MIN = min(MIN, cost)) {
    static tp v = 0;
    cost += (it->first - prev(it)->first) * (v += prev(it)->second);
  }
  cout << MIN;
  return 0;
}

signed __SOLUTION_LAND__::PRE() {
  return 0;
}