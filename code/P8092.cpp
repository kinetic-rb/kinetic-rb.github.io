#include <cstring>
#include <iostream>

using namespace std;
using tp = long long;
const tp Hat_N = 1000003;

tp val[Hat_N];

tp Func(tp i) {
  tp sum = 0;
  if (val[i] > val[i + 1]) {
    tp t = val[i] - val[i + 1];
    val[i - 1] -= t;
    val[i] -= t;
    sum += t << 1;
  }
  if (val[i] > val[i - 1]) {
    tp t = val[i] - val[i - 1];
    val[i + 1] -= t;
    val[i] -= t;
    sum += t << 1;
  }
  return sum;
}

tp Calc() {
  memset(val, 0x7f, sizeof val);
  tp ans = 0, n;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  if (n == 2) {
    return (val[1] == val[2] ? 0 : -1);
  }
  for (tp i = 2; i < n; ++i) {
    ans += Func(i);
  }
  for (tp i = n - 1; i > 1; --i) {
    ans += Func(i);
  }
  for (tp i = 1; i < n; ++i) {
    if (val[i] != val[i + 1] || val[i] < 0) {
      return -1;
    }
  }
  return ans;
}

signed main() {
  tp t;
  cin >> t;
  while (t--) {
    cout << Calc() << '\n';
  }
  return 0;
}