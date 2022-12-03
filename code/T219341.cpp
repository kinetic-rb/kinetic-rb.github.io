#include <iostream>
#include <deque>

using namespace std;
using tp = int;

signed main() {
  deque<tp> q;
  tp n;
  cin >> n;
  while (n--) {
    char op;
    cin >> op;
    if (op == 'I') {
      tp k;
      cin >> k;
      q.push_back(k);
    } else if (op == 'D') {
      q.pop_front();
    } else {
      tp k;
      cin >> k;
      cout << q[k] << ' ';
    }
  }
  return 0;
}