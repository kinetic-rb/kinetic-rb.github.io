#include <iostream>

using namespace std;
using bt = long long;

bt cc[128];

signed main() {
  bt n, k, sum = 0;
  char lim = 'z';
  string s;
  cin >> n >> k >> s;
  for (auto&& i : s) {
    ++cc[i];
  }
  for (char i = 'a'; i <= 'z'; ++i) {
    static bt cnt = 0;
    cnt += cc[i];
    if (cnt > k) {
      lim = i;
      break;
    }
  }
  for (char i = 'a'; i < lim; ++i) {
    sum += cc[i];
  }
  for (auto&& i : s) {
    if (i > lim) {
      cout << i;
    } else if (i == lim) {
      if (sum >= k) {
        cout << i;
      } else {
        ++sum;
      }
    }
  }
  return 0;
}