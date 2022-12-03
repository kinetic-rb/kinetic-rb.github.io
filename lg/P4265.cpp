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
  tp n = rv(), b = rv();
  vector<pair<tp, tp>> bt(b);
  vector<tp> snow(n);
  vector<vector<bool>> rb(b, vector<bool>(n, 0));
  rb[0][0] = 1;
  for (auto&& i : snow) {
    rv(i);
  }
  for (auto&& i : bt) {
    rv(i.first, i.second);
  }
  for (tp i = 0; i < b; ++i) {
    for (tp j = 0; j < n; ++j) {
      if (snow[j] > bt[i].first || rb[i][j]) {
        continue;
      }
      for (tp k = 0; k < j; ++k) {
        if (k + bt[i].second >= j && rb[i][k]) {
          if (j == n - 1) {
            cout << i;
            return 0;
          }
          rb[i][j] = 1;
          break;
        }
      }
      if (rb[i][j]) {
        continue;
      }
      for (tp k = 0; k < i; ++k) {
        if (rb[k][j]) {
          if (j == n - 1) {
            cout << i;
            return 0;
          }
          rb[i][j] = 1;
          break;
        }
      }
    }
  }
  return 0;
}

signed __SOLUTION_LAND__::PRE() {
  return 0;
}