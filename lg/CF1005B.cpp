#include <iostream>
#include <string>

using namespace std;
using vt = int;

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  string x, y;
  vt cnt = 0;
  cin >> x >> y;
  for (auto xp = x.rbegin(), yp = y.rbegin();
       xp != x.rend() && yp != y.rend() && *xp == *yp; ++xp, ++yp) {
    ++cnt;
  }
  cout << x.size() + y.size() - cnt * 2;
  return 0;
}