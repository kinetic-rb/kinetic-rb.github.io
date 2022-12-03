// By rbtree (https://rbtree.archi) :\
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
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
#define ra __Read()

using tp = long long;
tp __Read();
using namespace std;
constexpr tp Hat_N = 103;

signed main() {
  tp n = ra, m = ra;
  array<array<tp, Hat_N>, Hat_N> Bg, Eg;
  array<array<bool, Hat_N * Hat_N>, Hat_N> B, E;
  for (tp i = 0; i < Hat_N; ++i) {
    Bg[i].fill(-1ull >> 2);
    Eg[i].fill(-1ull >> 2);
    B[i].fill(0);
    E[i].fill(0);
  }
  B[1][0] = E[1][0] = 1;
  while (m--) {
    tp u = ra, v = ra;
    Bg[u][v] = min(Bg[u][v], ra);
    Eg[u][v] = min(Eg[u][v], ra);
  }
  for (tp i = 1; i < n; ++i) {
    for (tp j = 0; j < Hat_N * Hat_N; ++j) {
      for (tp k = i + 1; k <= n; ++k) {
        if (B[i][j] && Bg[i][k] != (-1ull >> 2)) {
          B[k][j + Bg[i][k]] = 1;
        }
        if (E[i][j] && Eg[i][k] != (-1ull >> 2)) {
          E[k][j + Eg[i][k]] = 1;
        }
      }
    }
  }
  for (tp i = 0; i < Hat_N * Hat_N; ++i) {
    if (B[n][i] && E[n][i]) {
      printf("%lld
", i);
      return 0;
    }
  }
  puts("IMPOSSIBLE");
  return 0;
}

tp __Read() {
  bool __Negitive = 0;
  char __Char = getchar();
  tp __Value;
  for (; __Char < 48 || __Char > 57; __Char = getchar()) {
    __Negitive = __Char == 45;
  }
  __Value = __Char & 15;
  for (__Char = getchar(); __Char > 47 && __Char < 58; __Char = getchar()) {
    __Value = __Value * 10 + (__Char & 15);
  }
  return __Negitive ? ~__Value + 1 : __Value;
}