// Please submit with C++14! It's best to use C++17 or higher version.
#ifndef LOCAL
#pragma region HEAD  // Spectre
#endif
#include <algorithm>  // By rbtree (https://rbtree.archi)
#include <array>
#include <bitset>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#endif
#define ra (scanf("%lld", &la), la)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fitp(__Val), __target;
}

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

vector<tp> p({1,         2,          4,          6,         12,
              24,        36,         48,         60,        120,
              180,       240,        360,        720,       840,
              1260,      1680,       2520,       5040,      7560,
              10080,     15120,      20160,      25200,     27720,
              45360,     50400,      55440,      83160,     110880,
              166320,    221760,     277200,     332640,    498960,
              554400,    665280,     720720,     1081080,   1441440,
              2162160,   2882880,    3603600,    4324320,   6486480,
              7207200,   8648640,    10810800,   14414400,  17297280,
              21621600,  32432400,   36756720,   43243200,  61261200,
              73513440,  110270160,  122522400,  147026880, 183783600,
              245044800, 294053760,  367567200,  551350800, 698377680,
              735134400, 1102701600, 1396755360, 2001000000});

signed main() {
  printf("%lld
", *--upper_bound(p.begin(), p.end(), ra));
  return 0;
}

////////////////////////////////////////////////////////////////////////////////