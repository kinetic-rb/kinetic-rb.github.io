#include <iostream>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 200003, Hat_V = 103;

vt num[Hat_N], cnt[Hat_V];

signed main() {
  vt n;
  cin >> n;
  for (vt i = 0; i < n; ++i) {
    cin >> num[i];
    ++cnt[num[i]];
  }
  for (vt i = 0; i < n; ++i) {
    cout << cnt[num[i]] << ' ';
  }
  return 0;
}