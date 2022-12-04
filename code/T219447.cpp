#include <algorithm>
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
// #define __NEGATIVE_NUMBER__
using namespace std;
using tp = long long;
FILE* __STREAM__ = stdin;
constexpr bool __MTCS__ = 0;
constexpr size_t __Buf_Size__ = 114514'1;

namespace {
namespace AE86 {
bool State = 1;
bool __Pre_State__ = 1;
char __;
#ifndef __LOCAL__DEBUG__
char *__begin, *__end;
char __buf[__Buf_Size__];
#endif

void fetch() {
#ifdef __LOCAL__DEBUG__
  if ((__ = fgetc(__STREAM__)) == -1) {
    State = 0;
  }
#else
  if (__begin == __end) {
    __end = __buf + fread(__begin = __buf, 1, __Buf_Size__, __STREAM__);
    if (__begin == __end) {
      return static_cast<void>(tie(__Pre_State__ ? __Pre_State__ : State, __) =
                                   make_pair(0, -1));
    }
  }
  __ = *__begin++;
#endif
}

signed rc(char& __VALUE__) {
  for (; __ == 32 || __ == 10 || __ == 9 || __ == 12 || __ == 11; fetch()) {
    if (!__Pre_State__) {
      __VALUE__ = -1;
      return State;
    }
  }
  __VALUE__ = __;
  fetch();
  return State;
}

signed rcs(char* __VALUE__) {
  for (; __ == 32 || __ == 10 || __ == 9 || __ == 12 || __ == 11; fetch()) {
    if (!__Pre_State__) {
      return State;
    }
  }
  for (; __ != 32 && __ != 10 && __ != 9 && __ != 12 && __ != 11; fetch()) {
    if (!__Pre_State__) {
      return State;
    }
    *__VALUE__++ = __;
  }
  return State;
}

signed rs(std::string& __VALUE__) {
  for (; __ == 32 || __ == 10 || __ == 9 || __ == 12 || __ == 11; fetch()) {
    if (!__Pre_State__) {
      return State;
    }
  }
  for (__VALUE__.clear();
       __ != 32 && __ != 10 && __ != 9 && __ != 12 && __ != 11; fetch()) {
    if (!__Pre_State__) {
      return State;
    }
    __VALUE__.push_back(__);
  }
  return State;
}

template <typename _Typex>
signed rv(_Typex& __VALUE__) {
#ifdef __NEGATIVE_NUMBER__
  bool __negative = 0;
  for (; __ < 48 || __ > 57; fetch()) {
    if (!__Pre_State__) {
      return State;
    }
    __negative = __ == 45;
  }
  for (__VALUE__ = 0; __ > 47 && __ < 58 && __Pre_State__; fetch()) {
    __VALUE__ = __VALUE__ * 10 + (__negative ? -(__ & 15) : __ & 15);
  }
#else
  for (; __ < 48 || __ > 57; fetch()) {
    if (!__Pre_State__) {
      return State;
    }
  }
  for (__VALUE__ = 0; __ > 47 && __ < 58 && __Pre_State__; fetch()) {
    __VALUE__ = __VALUE__ * 10 + (__ & 15);
  }
#endif
  return State;
}

template <typename _Typex = tp>
_Typex rv() {
  _Typex __VALUE__;
  rv(__VALUE__);
  return __VALUE__;
}

template <typename _Typex, typename... _Args>
signed rv(_Typex& __VALUE__, _Args&... __Args__) {
  if (rv(__VALUE__)) {
    rv(__Args__...);
  }
  return State;
}

struct __Initer_t__ {
  __Initer_t__() { fetch(); }
} __Initer__;
}  // namespace AE86

using AE86::rv, AE86::rc, AE86::rcs, AE86::rs;

namespace __SOLUTION_LAND__ {
signed main();
signed PRE();
}  // namespace __SOLUTION_LAND__
}  // namespace
signed main() {
  static signed __P__ = __SOLUTION_LAND__::PRE(), __T__ = __MTCS__ ? rv() : 1;
  return __T__-- && (main() || __SOLUTION_LAND__::main()) ? -1 : __P__;
}

/** @b @note The following is the main part **/

/** @b @note The following is the core of the main part **/

signed __SOLUTION_LAND__::main() {
  tp n = rv(), x = rv();
  vector<bool> uu(n + 1, 1);
  vector<tp> fact(n + 1, 1);
  for (tp i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  while (n--) {
    for (tp i = 1;; ++i) {
      if (uu[i]) {
        if (x <= fact[n]) {
          cout << i << ' ';
          uu[i] = 0;
          break;
        }
        x -= fact[n];
      }
    }
  }
  return 0;
}

signed __SOLUTION_LAND__::PRE() {
  return 0;
}