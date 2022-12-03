#include <iostream>
#include <queue>

using namespace std;
using tp = int_fast64_t;

priority_queue<tp> tm;

tp fj(tp n) {
  static bool vis = 1;
  tp cnt = 0;
  for (tp i = 1ll << 60; i; i >>= 1) {
    if (n & i) {
      if (vis) {
        tm.push(i);
      }
      ++cnt;
    }
  }
  vis = 0;
  return cnt;
}

signed main() {
  tp n, k;
  cin >> n >> k;
  if (k > n || k < fj(n)) {
    puts("NO");
    return 0;
  }
  puts("YES");
  k -= fj(n);
  while (k) {
    tp x = tm.top() >> 1;
    tm.pop();
    tm.push(x);
    tm.push(x);
    --k;
  }
  while (tm.size()) {
    cout << tm.top() << ' ';
    tm.pop();
  }
  return 0;
}