#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using dt = long long;

dt Mlog(dt n) {
  dt np = 1;
  while (n >>= 1) {
    np <<= 1;
  }
  return np;
}

vector<dt> F2(dt n) {
  vector<dt> res;
  while (n) {
    dt m = Mlog(n);
    n -= m;
    res.push_back(m);
  }
  return res;
}

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  dt n;
  cin >> n;
  if (n & 1) {
    cout << -1;
    return 0;
  }
  vector<dt> res = F2(n);
  for (auto&& i : res) {
    cout << i << ' ';
  }
  return 0;
}