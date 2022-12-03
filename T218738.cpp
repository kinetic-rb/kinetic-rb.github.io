#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using tp = int;

vector<tp> v[5003];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n, m;
  cin >> n >> m;
  while (m--) {
    tp x, y;
    cin >> x >> y;
    v[x].push_back(y);
  }
  for (tp i = 1; i <= n; ++i) {
    reverse(v[i].begin(), v[i].end());
    for (auto&& x : v[i]) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}