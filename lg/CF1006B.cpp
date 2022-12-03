#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using dt = long long;

dt num[2003], t[2003];
bool used[2003];

signed main() {
  vector<dt> res;
  dt n, k, sum = 0, last = 0;
  cin >> n >> k;
  for (dt i = 1; i <= n; ++i) {
    cin >> num[i];
    t[i] = num[i];
  }
  stable_sort(num + 1, num + n + 1);
  reverse(num + 1, num + n + 1);
  for (dt i = 1; i <= n; ++i) {
    bool f = false;
    for (dt j = 1; j <= k; ++j) {
      if (t[i] == num[j] && !used[j]) {
        f  = used[j] = true;
        break;
      }
    }
    if (f) {
      res.push_back(i);
      sum += t[i];
    }
  }
  cout << sum << '\n';
  res[k - 1] = n;
  for (dt i = 0; i < k; ++i) {
    cout << res[i] - last << ' ';
    last = res[i];
  }
  return 0;
}