// By rbtree (https://rbtree.archi) :\
// Please submit with C++14!
#include <algorithm>
#include <array>
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
constexpr tp Hat_N = 2003;

signed main() {
  tp n = ra, sum = 0;
  set<tp> c;
  array<tp, Hat_N> a, f;
  f.fill(0);
  f[0] = -114514;
  for (tp i = 1; i <= n; ++i) {
    c.insert(i);
    a[i] = ra;
  }
  while (c.size()) {
    tp bt = 0;
    for_each(c.begin(), c.end(), [&](tp i) { bt = f[i] > f[bt] ? i : bt; });
    c.erase(bt);
    sum += f[bt];
    for_each(c.begin(), c.end(), [&](tp i) { f[i] = max(f[i], a[i] ^ a[bt]); });
  }
  printf("%lld
", sum);
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