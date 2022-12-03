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
constexpr bool __MTCS__ = 1;
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

constexpr tp Hat_S = 1e5;

/** @note The following is the core of the main part. **/

vector<tp> c;
map<tp, tp> f;

signed __SOLUTION_LAND__::main() {
  vector<tp> d = {rv(), rv(), rv(), rv()};
  tp s = rv(), tar = f[s];
  for (tp i = 1; i < 16; ++i) {
    bool v = 1;
    tp sum = 0 ;
    for (tp j = 0; j < 4; ++j) {
      if (i >> j & 1) {
        v ^= 1;
        sum += c[j] * (d[j] + 1);
      }
    }
    if (s >= sum) {
      tar += (v ? 1 : -1) * f[s - sum];
    }
  }
  cout << tar << '\n';
  return 0;
}

signed __SOLUTION_LAND__::PRE() {
  c = {rv(), rv(), rv(), rv()};
  f[0] = 1;
  for (auto&& c : c) {
    for (tp i = c; i <= Hat_S; ++i) {
      f[i] += f[i - c];
    }
  }
  return 0;
}