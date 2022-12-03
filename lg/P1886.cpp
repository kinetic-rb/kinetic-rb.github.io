#include <iostream>
#include <list>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 1000003;

tp num[Hat_N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n, k;
  list<tp> q;
  cin >> n >> k;
  for (tp i = 0; i < n; ++i) {
    static tp h = 0;
    cin >> num[i];
    while (q.size() && q.back() >= num[i]) {
      q.pop_back();
    }
    q.push_back(num[i]);
    if (i - h >= k && num[h] == q.front()) {
      ++h;
      q.pop_front();
    }
    if (i - h >= k && num[h] != q.front()) {
      ++h;
    }
    if (i >= k - 1) {
      cout << q.front() << ' ';
    }
  }
  cout << '\n';
  q.clear();
  for (tp i = 0; i < n; ++i) {
    static tp h = 0;
    while (q.size() && q.back() <= num[i]) {
      q.pop_back();
    }
    q.push_back(num[i]);
    if (i - h >= k && num[h] == q.front()) {
      ++h;
      q.pop_front();
    }
    if (i - h >= k && num[h] != q.front()) {
      ++h;
    }
    if (i >= k - 1) {
      cout << q.front() << ' ';
    }
  }
  return 0;
}