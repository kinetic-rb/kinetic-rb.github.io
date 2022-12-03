#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#define tpt "%lld"
#define rtp(__VALUE__) scanf(tpt, &__VALUE__)

using namespace std;
using tp = long long;
constexpr bool _TESTS_ = 1;

namespace _SOL_ {
signed main() {
  tp n, k, tl, tr, MAX = 0;
  map<tp, tp> cnt;
  vector<tp> ok;
  scanf(tpt tpt, &n, &k);
  for (tp i = 0; i < n; ++i) {
    tp x;
    rtp(x);
    ++cnt[x];
  }
  for (auto&& [x, y] : cnt) {
    if (y >= k) {
      ok.push_back(x);
    }
  }
  for (tp i = 0; i < ok.size();) {
    tp left = i++;
    while (i < ok.size() && ok[i] == ok[i - 1] + 1) {
      ++i;
    }
    if (i - left > MAX) {
      tie(tl, tr, MAX) = make_tuple(left, i - 1, i - left);
    }
  }
  if (tl >= ok.size() || tr >= ok.size()) {
    puts("-1");
  } else {
    cout << ok[tl] << ' ' << ok[tr] << '\n';
  }
  return 0;
}

signed _PRE_() {
  return 0;
}
}  // namespace _SOL_

signed main() {
  static tp _P_ = _SOL_::_PRE_(), T_ = 1, _R_ = scanf(_TESTS_ ? tpt : "", &T_);
  return T_-- && (main() || _SOL_::main()) ? -1 : _P_;
}