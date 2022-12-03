#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using tp = long long int;

tp m;
vector<char> d;
vector<pair<tp, tp>> go;

struct Item_t {
  tp p, r;

  Item_t() = default;
  Item_t(tp _p, tp _r) : p(_p), r(_r) {}

  Item_t move() {
    p = (d[r] == 'L' ? go[p].first : go[p].second);
    r = (r + 1) % m;
    return *this;
  }

  bool operator==(const Item_t& comp) const {
    return p == comp.p && r == comp.r;
  }

  bool operator!=(const Item_t& comp) const {
    return !(*this == comp);
  }
};

signed main() {
  tp n, k;
  Item_t _1(1, 0), _2(1, 0);
  scanf("%lld%lld%lld", &n, &m, &k);
  k *= m;
  d = vector<char>(m);
  go = vector<pair<tp, tp>>(n + 1);
  for (tp i = 1; i <= n; ++i) {
    scanf("%lld%lld", &go[i].first, &go[i].second);
  }
  for (auto&& i : d) {
    cin >> i;
  }
  while (k--) {
    _2.move();
    if (_1.move() == _2.move()) {
      break;
    }
  }
  k += !~k;
  if (k) {
    tp cnt = 1;
    while (_1.move() != _2) {
      ++cnt;
    }
    for (k %= cnt; k--; _1.move()) {
    }
  }
  cout << _1.p << '\n';
  return 0;
}