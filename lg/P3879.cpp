#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using tp = long long int;

signed main() {
  tp n;
  map<string, vector<tp>> app;
  cin >> n;
  for (tp i = 1, m; i <= n; ++i) {
    cin >> m;
    for (string s; m--; app[s].push_back(i)) {
      cin >> s;
    }
  }
  for (cin >> n; auto&& [_, i] : app) {
    i.resize(unique(i.begin(), i.end()) - i.begin());
  }
  for (string s; n--; for_each(app[s].begin(), app[s].end(), [](auto&& i) { cout << i << ' '; }), cout << '\n') {
    cin >> s;
  }
  return 0;
}