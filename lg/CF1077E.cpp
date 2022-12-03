#include <iostream>
#include <map>
#include <queue>

using namespace std;
using tp = int32_t;

map<tp, tp> p;
priority_queue<tp> q;

signed main() {
  tp n, t = -114514, target = -1919810;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  while (n--) {
    tp x;
    cin >> x;
    p[x]++;
  }
  for (auto&& [x, y] : p) {
    q.push(y);
    if (y > t) {
      t = y;
    }
  }
  for (tp c = 0; t && q.size(); t >>= 1) {
    t = min(q.top(), t);
    target = max(target, ((1 << ++c) - 1) * t);
    q.pop();
  }
  cout << target;
  return 0;
}