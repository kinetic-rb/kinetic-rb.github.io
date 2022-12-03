#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
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
  tp l = rv(), n = rv(), sf = rv(), sb = rv(), sum = 0;
  vector<tp> loc(n), v(n);
  vector<bool> suf(n, 0);
  for (tp i = 0; i < n; ++i) {
    rv(loc[i], v[i]);
  }
  for (tp i = n, MAX = 0; ~--i; MAX = max(MAX, v[i])) {
    suf[i] = v[i] > MAX;
  }
  for (tp i = 0; i < n; ++i) {
    if (suf[i]) {
      static tp loc_last = 0;
      tp f = (loc[i] - loc_last) * sf, b = (loc[i] - loc_last) * sb;
      sum += (f - b) * v[i];
      loc_last = loc[i];
    }
  }
  cout << sum;
  return 0;
}

signed __SOLUTION_LAND__::PRE() {
  return 0;
}