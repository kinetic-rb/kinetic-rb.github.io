#include <iostream>
#include <set>

using namespace std;
using vt = long long;

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n;
  cin >> n;
  set<vt> b;
  for (vt i = 0; i < n; ++i) {
    vt x;
    cin >> x;
    b.insert(x);
  }
  for (auto&& i : b) {
    cout << i << ' ';
  }
  return 0;
}