#include <iostream>
#include <map>

using namespace std;
using vt = int;

template <typename MAP>
vt Calc(MAP mo) {
  vt n, sum = 0;
  cin >> n;
  while (mo.size()) {
    sum += min(n / mo.rbegin()->first, mo.rbegin()->second);
    n -= min(n / mo.rbegin()->first, mo.rbegin()->second) * mo.rbegin()->first;
    mo.erase(--mo.end());
  }
  return n ? -1 : sum;
}

signed main() {
  vt n, m;
  map<vt, vt> t;
  cin >> n >> m;
  for (vt x; n--; ++t[x]) {
    cin >> x;
  }
  while (m--) {
    cout << Calc(t) << '\n';
  }
  return 0;
}