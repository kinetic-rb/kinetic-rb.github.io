#include <iostream>
#include <unordered_map>

using namespace std;
using dt = long long;

signed main() {
  ios_base::sync_with_stdio(false);
  dt n, m, res = 0;
  char ch;
  string a, b;
  cin >> n >> a >> b;
  m = n >> 1;
  for (dt i = 0; i < m; ++i) {
    static unordered_map<char, dt> cnt;
    cnt.clear();
    ++cnt[a[i]];
    ++cnt[a[n - i - 1]];
    ++cnt[b[i]];
    ++cnt[b[n - i - 1]];
    if (cnt.size() == 2) {
      if (cnt[a[i]] != 2) {
        ++res;
      }
    } else if (cnt.size() == 3) {
      ++res;
      if (a[i] == a[n - i - 1]) {
        ++res;
      }
    } else if (cnt.size() == 4) {
      res += 2;
    }
  }
  if (n & 1 && a[m] != b[m]) {
    ++res;
  }
  cout << res;
  return 0;
}