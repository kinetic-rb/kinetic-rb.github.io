#include <iostream>
#include <deque>

using namespace std;
using tp = long long;

signed main() {
  deque<tp> q;
  tp n;
  cin >> n;
  while (n--) {
    char op;
    cin >> op;
    if (op == 'I') {
      tp k, x, y, now = 1;
      cin >> k >> x >> y;
      while (k--) {
        q.push_back((now * x + y) % 1000000007);
        now = (now * x + y) % 1000000007;
      }
    } else if (op == 'D') {
      tp k;
      cin >> k;
      while (k--) {
        q.pop_front();
      }
    } else {
      tp k;
      cin >> k;
      cout << q[k] << ' ';
    }
  }
  return 0;
}