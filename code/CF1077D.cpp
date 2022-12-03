#include <iostream>

using namespace std;
using tp = int64_t;
const tp Hat_N = 200003;

tp cnt[Hat_N];
tp k;

bool check(tp x) {
  tp sum = 0;
  for (tp i = 1; i < Hat_N; ++i) {
    sum += cnt[i] / x;
  }
  return sum >= k;
}

tp fs() {
  tp qloc = 0;
  for (tp loc = 1 << 30; loc; loc >>= 1) {
    if (check(qloc + loc)) {
      qloc += loc;
    }
  }
  return qloc;
}

signed main() {
  tp n, loc;
  cin >> n >> k;
  while (n--) {
    tp x;
    cin >> x;
    ++cnt[x];
  }
  loc = fs();
  for (tp i = 0; i < Hat_N; ++i) {
    while (cnt[i] >= loc && k) {
      cout << i << ' ';
      cnt[i] -= loc;
      --k;
    }
  }
  cout << '\n';
  return 0;
}