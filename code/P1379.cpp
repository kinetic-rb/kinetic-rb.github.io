#include <array>
#include <iostream>
#include <queue>
#include <set>

using namespace std;
using tp = intmax_t;
using ra = array<tp, 9>;
constexpr tp end_ra[] = {1, 2, 3, 8, 0, 4, 7, 6, 5};

tp EnCode(ra m) {
  tp sum = 0, P = 1;
  for (auto&& i : m) {
    sum += P * i;
    P *= 9;
  }
  return sum;
}

ra DeCode(tp m) {
  ra p;
  for (auto&& i : p) {
    i = m % 9;
    m /= 9;
  }
  return p;
}

tp A_Star(ra s) {
  struct QNode {
    tp f, m, step;

    QNode() = default;
    QNode(tp _f, tp _m, tp _step) : f(_f), m(_m), step(_step) {}
    bool operator<(const QNode& comp) const {
      return step > comp.step;
    }
  };
  priority_queue<QNode> p;
  set<tp> vis;
  auto h = [](ra m) -> tp {
    tp cnt = 0;
    for (tp i = 0; i < 9; ++i) {
      cnt += m[i] != end_ra[i];
    }
    return cnt;
  };
  auto record = [&](tp m, tp step) -> void {
    if (!vis.count(m)) {
      vis.insert(m);
      p.push(QNode(h(DeCode(m)) + step, m, step));
    }
  };
  for (record(EnCode(s), 0); p.size(); p.pop()) {
    ra m = DeCode(p.top().m);
    if (!h(m)) {
      return p.top().step;
    }
    tp loc;
    for (tp i = 0; i < 9; ++i) {
      if (!m[i]) {
        loc = i;
        break;
      }
    }
    if (loc % 3 != 2) {
      swap(m[loc], m[loc + 1]);
      record(EnCode(m), p.top().step + 1);
      swap(m[loc], m[loc + 1]);
    }
    if (loc % 3) {
      swap(m[loc], m[loc - 1]);
      record(EnCode(m), p.top().step + 1);
      swap(m[loc], m[loc - 1]);
    }
    if (loc >= 3) {
      swap(m[loc], m[loc - 3]);
      record(EnCode(m), p.top().step + 1);
      swap(m[loc], m[loc - 3]);
    }
    if (loc < 6) {
      swap(m[loc], m[loc + 3]);
      record(EnCode(m), p.top().step + 1);
      swap(m[loc], m[loc + 3]);
    }
  }
  return -1;
}

signed main() {
  ra s;
  for (auto&& i : s) {
    char ch;
    cin >> ch;
    i = ch ^ 48;
  }
  cout << A_Star(s) << '\n';
  return 0;
}

/*
123
804
765
*/
