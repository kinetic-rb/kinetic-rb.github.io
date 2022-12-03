#include <iostream>
#include <queue>

using namespace std;
using vt = long long;

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n, m, Minsum = 0, Maxsum = 0, cnt = 0;
  priority_queue<vt> Mm;
  cin >> n >> m;
  for (vt i = 0; i < n; ++i) {
    vt mx, mn;
    cin >> mx >> mn;
    Maxsum += mx;
    Minsum += mn;
    Mm.push(mx - mn);
  }
  if (Minsum > m) {
    cout << -1;
    return 0;
  }
  while (Maxsum > m) {
    Maxsum -= Mm.top();
    Mm.pop();
    ++cnt;
  }
  cout << cnt;
  return 0;
}