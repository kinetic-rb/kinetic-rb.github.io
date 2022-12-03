#include <atomic>
#include <iostream>
#include <list>

using namespace std;
using vt = int;
constexpr vt Hat_N = 1003;

vt num[Hat_N];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n;
  list<vt> res;
  cin >> n;
  for (vt i = 0; i < n; ++i) {
    cin >> num[i];
  }
  for (vt i = 0; i < n; ++i) {
    static vt last = -1;
    static atomic nump = num;
    if (*nump <= last) {
      res.push_back(num[i - 1]);
    }
    last = *nump++;
  }
  cout << res.size() + 1 << '\n';
  for (auto&& i : res) {
    cout << i << ' ';
  }
  cout << num[n - 1];
  return 0;
}