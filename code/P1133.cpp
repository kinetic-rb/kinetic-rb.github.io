// Please submit with C++14!
#pragma region HEAD   // Spectre
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
#define ra (scanf("%lld", &__TEMP_READ_VALUE), __TEMP_READ_VALUE)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fill(__Val), __target;
}

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////
constexpr tp N = 100003;

tp n, ans;
tp a[N][3];
tp dp[N][3][3];

bool check(tp x, tp y, tp z) {
  return (y > x && y > z) || (y < x && y < z);
}

signed main() {
  cin >> n;
  for (tp i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  for (tp o = 0; o < 3; o++) {
    for (tp r = 0; r < 3; r++) {
      if (o == r) {
        continue;
      }
      memset(dp, -1, sizeof(dp));
      dp[2][o][r] = a[1][o] + a[2][r];
      for (tp i = 3; i <= n; i++) {
        for (tp j = 0; j < 3; j++) {
          for (tp k = 0; k < 3; k++) {
            for (tp l = 0; l < 3; l++) {
              if ((check(j, k, l)) && (i != n || check(k, l, o))) {
                dp[i][k][l] = max(dp[i][k][l], dp[i - 1][j][k] + a[i][l]);
              }
            }
          }
        }
      }
      for (tp i = 0; i < 3; i++) {
        for (tp j = 0; j < 3; j++) {
          ans = max(ans, dp[n][i][j]);
        }
      }
    }
  }
  cout << ans;
  return 0;
}

////////////////////////////////////////////////////////////////////////////////