#include <atomic>
#include <iostream>
#include <set>
 
using namespace std;
using vt = long long;
constexpr vt Hat_N = 120003, Hat_Pow = 1 << 30;
 
multiset<vt> exist;
vt num[Hat_N];
 
signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n, cnt = 0;
  cin >> n;
  for (vt i = 0; i < n; ++i) {
    cin >> num[i];
    exist.insert(num[i]);
  }
  for (vt i = 0; i < n; ++i) {
    exist.erase(exist.lower_bound(num[i]));
    vt pow = 1;
    bool can = true;
    while (pow <= num[i]) {
      pow *= 2;
    }
    while (pow <= Hat_Pow) {
      if (exist.count(pow - num[i])) {
        can = false;
        break;
      }
      pow *= 2;
    }
    if (can) {
      ++cnt;
    }
    exist.insert(num[i]);
  }
  cout << cnt;
  return 0;
}