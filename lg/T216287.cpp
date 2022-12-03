#include <bitset>
#include <iostream>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 100003;

bitset<Hat_N> ap;

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n;
  cin >> n;
  while (n--) {
    vt x;
    cin >> x;
    ap[x] = true;
  }
  for (vt i = 0; i < Hat_N; ++i) {
    if (ap[i]) {
      cout << i << ' ';
    }
  }
  return 0;
}