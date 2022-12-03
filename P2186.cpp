// Please submit with C++14! It's best to use C++20 or higher version.
#ifndef LOCAL        // Spectre
#pragma region HEAD  // By rbtree (https://rbtree.dev)
#endif
#include <algorithm>
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
#define se(exp) exp.begin(), exp.end()
#define fe(arr, exp) for_each(se(arr), exp)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

constexpr bool __MTCS__ = 0;

////////////////////////////////////////////////////////////////////////////////

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n;
  list<pair<string, tp>> op;
  for (string s; cin >> s, s != "END";) {
    if (s == "NUM") {
      op.emplace_back(s, ra);
    } else {
      op.emplace_back(s, 0);
    }
  }
  n = ra;
  while (n--) {
    bool f = 0;
    list<tp> s({ra});
    for (auto&& [i, j] : op) {
      if (i == "NUM") {
        s.push_back(j);
      } else if (i == "POP") {
        s.pop_back();
      } else if (i == "INV") {
        tp t = s.back();
        s.pop_back();
        s.push_back(-t);
      } else if (i == "DUP") {
        s.push_back(s.back());
      } else {
        tp a = s.back(), b = (s.pop_back(), s.back());
        s.pop_back();
        if (i == "SWP") {
          s.push_back(a);
          s.push_back(b);
        } else if (i == "ADD") {
          s.push_back(a + b);
        } else if (i == "SUB") {
          s.push_back(b - a);
        } else if (i == "MUL") {
          s.push_back(a * b);
        } else if (!a) {
          f = 1;
          break;
        } else if (i == "DIV") {
          s.push_back(b / a);
        } else if (i == "MOD") {
          s.push_back(b % a);
        }
        if (abs(s.back()) > 1e9) {
          f = 1;
          break;
        }
      }
    }
    if (f || s.size() != 1) {
      puts("ERROR");
    } else {
      printf("%lld
", s.front());
    }
  }
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}