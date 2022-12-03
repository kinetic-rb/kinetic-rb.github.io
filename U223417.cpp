#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using tp = int_fast64_t;
constexpr tp Hat_N = 18;

tp temp[Hat_N];
tp n;

void DeCode(tp e) {
  memset(temp, 0, sizeof temp);
  tp cnt = 0;
  while (e) {
    temp[++cnt] = e & 15;
    e >>= 4;
  }
}

tp h(tp e) {
  DeCode(e);
  tp cnt = 1;
  for (tp i = 1; i <= n; ++i) {
    cnt += temp[i] != i;
  }
  return cnt >> 1;
}

struct QNode {
  tp f, Ra, step;

  QNode() = default;
  QNode(tp _f, tp _Ra, tp _step) : f(_f), Ra(_Ra), step(_step) {}

  bool operator<(const QNode& comp) const { return f > comp.f; }
};

tp EnCode() {
  tp sum = 0;
  for (tp i = 1, P = 1; i <= n; ++i) {
    sum += P * temp[i];
    P <<= 4;
  }
  return sum;
}

tp Rswap(tp e, tp i, tp j) {
  DeCode(e);
  swap(temp[i], temp[j]);
  return EnCode();
}

void A_Star(tp s) {
  priority_queue<QNode> q;
  set<tp> vis;
  auto record = [&](tp e, tp step) -> void {
    if (!vis.count(e) && h(e) + step <= 8) {
      vis.insert(e);
      q.emplace(h(e) + step, e, step);
    }
  };
  for (record(s, 0); q.size(); q.pop()) {
    if (!h(q.top().Ra)) {
      printf("%lld
", q.top().step);
      return;
    }
    for (tp i = 1; i < n; ++i) {
      for (tp j = i + 1; j <= n; ++j) {
        record(Rswap(q.top().Ra, i, j), q.top().step + 1);
      }
    }
  }
  puts("Error");
}

signed main() {
  tp t;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (tp i = 1; i <= n; ++i) {
      scanf("%lld", temp + i);
    }
    A_Star(EnCode());
  }
  return 0;
}