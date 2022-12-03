#include <iostream>
#include <set>

using namespace std;
using tp = int64_t;

signed main() {
  tp n, MAX;
  multiset<tp> app;
  cin >> n;
  for (tp x; n--; app.insert(x)) {
    cin >> x;
  }
  MAX = *app.rbegin();
  for (tp i = 1; i <= MAX; ++i) {
    if (!(MAX % i)) {
      if (app.count(i) == 2) {
        app.erase(i);
        app.insert(i);
      } else {
        app.erase(i);
      }
    }
  }
  cout << MAX << ' ' << *app.rbegin();
  return 0;
}