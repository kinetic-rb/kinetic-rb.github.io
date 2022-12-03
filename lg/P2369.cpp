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

signed main() {
  tp n = ra, m = ra;
  priority_queue<tp> s;
  priority_queue<tp, vector<tp>, greater<tp>> t;
  while (n--) {
    s.push(ra);
    if (s.size() > m) {
      s.pop();
    }
  }
  while (s.size()) {
    t.push(s.top());
    s.pop();
  }
  while (t.size()) {
    printf("%lld
", t.top());
    t.pop();
  }
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