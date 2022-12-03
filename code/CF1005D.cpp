#include <iostream>

using namespace std;
using vt = int;

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  string x;
  vt cnt = 0;
  cin >> x;
  for (auto&& i : x) {
    i ^= 48;
  }
  for (auto&& i : x) {
    static vt sum = 0, b = 0;
    sum += i;
    ++b;
    if (!(sum % 3) || !(i % 3) || b == 3) {
      ++cnt;
      sum = b = 0;
    }
  }
  cout << cnt;
  return 0;
}