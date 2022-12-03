#include <iostream>
#include <list>

using namespace std;
using tp = intmax_t;

tp v[1000005], cnt[200005];

signed main() {
  tp n, sum = 0;
  list<tp> res;
  cin >> n;
  for (tp i = 0; i < n; ++i) {
    cin >> v[i];
    ++cnt[v[i]];
    sum += v[i];
  }
  for (tp i = 0; i < n; ++i) {
    --cnt[v[i]];
    sum -= v[i];
    if (~sum & 1 && sum >> 1 <= 1000000 && cnt[sum >> 1]) {
      res.push_back(i + 1);
    }
    ++cnt[v[i]];
    sum += v[i];
  }
  cout << res.size() << '\n';
  for (auto&& i : res) {
    cout << i << ' ';
  }
  return 0;
}