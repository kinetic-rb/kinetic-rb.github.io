#include <iostream>
#include <stack>

using namespace std;
using tp = long long;

struct SNode {
  tp val, id;

  SNode() = default;
  SNode(tp _val, tp _id) : val(_val), id(_id) {}
};

stack<SNode> s;

void add(tp val) {
  static tp cnt = 0;
  s.emplace(val, cnt++);
}

void add() {
  tp val;
  cin >> val;
  add(val);
}

signed main() {
  tp n, sum = 0;
  cin >> n;
  add();
  for (tp i(1); i ^ n; ++i) {
    tp val;
    cin >> val;
    sum += i - s.top().id + 1;
    if (s.size() && val > s.top().val) {
      s.pop();
      while (s.size() && val > s.top().val) {
        sum += i - s.top().id + 1;
        s.pop();
      }
      if (s.size()) {
        sum += i - s.top().id + 1;
      }
    }
    add(val);
  }
  cout << sum;
  return 0;
}