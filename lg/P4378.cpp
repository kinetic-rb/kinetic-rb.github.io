#include <algorithm>
#include <iostream>

using namespace std;
using vt = long long;

pair<vt, vt> num[100000];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n, ans = 0;
  cin >> n;
  for (vt i = 0; i < n; i++) {
    cin >> num[i].first;
    num[i].second = i;
  }
  stable_sort(num, num + n);
  for (vt j = 0; j < n; j++) {
    if (num[j].second - j > ans) {
      ans = num[j].second - j;
    }
  }
  cout << ans + 1;
  return 0;
}