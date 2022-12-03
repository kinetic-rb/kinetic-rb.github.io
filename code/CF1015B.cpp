#include <iostream>
#include <list>

using namespace std;
using vt = long long;

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  string s, t;
  list<vt> res;
  vt n;
  cin >> n >> s >> t;
  for (vt i = 0; i < n; ++i) {
    vt j = i;
    while (s[j] != t[i]) {
      if (j++ == n) {
        cout << -1;
        return 0;
      }
    }
    while (j > i) {
      s[j] ^= s[j - 1] ^= s[j] ^= s[j - 1];
      res.push_back(j--);
    }
  }
  cout << res.size() << '\n';
  for (auto&& i : res) {
    cout << i << ' ';
  }
  return 0;
}