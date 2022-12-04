/*
\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000 \u2227\uff3f\u2227
\u3000\u3000\u3000\u3000\u3000 \u2227\uff3f\u2227 \u3000\uff08\u00b4<_\uff40 \uff09\u3000 Welcome to My Coding Space ^_^
\u3000\u3000\u3000\u3000 \uff08 \u00b4_\u309d`\uff09\u3000/\u3000 \u2312i
\u3000\u3000\u3000\u3000\uff0f\u3000\u3000\u3000\uff3c\u3000 \u3000  |\u3000|
\u3000\u3000\u3000 /\u3000\u3000 /\uffe3\uffe3\uffe3\uffe3/\u3000|\u3000|
\u3000 \uff3f_(__\uff86\u3064/\u3000\u3000 \u3000 / .| .|\uff3f\uff3f\uff3f\uff3f
\u3000 \u3000\u3000\u3000\uff3c/\uff3f\uff3f\uff3f\uff3f/\u3000\uff08u\u3000\u2283
*/

#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;
using tp = int64_t;
const tp Hat_N = 1503;

struct Rs {
  tp s, r, l;

  Rs() = default;
  Rs(tp _s, tp _r, tp _l) : s(_s), r(_r), l(_l) {}
  auto operator<=>(const Rs&) const = default;
};
tp s[Hat_N];

signed main() {
  tp n;
  list<pair<tp, tp>> tar, t;
  set<Rs> e;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    cin >> s[i];
    s[i] += s[i - 1];
    for (tp j = 1; j <= i; ++j) {
      e.emplace(s[i] - s[j - 1], i, j);
    }
  }
  for (auto&& i : e) {
    static bool f = 1;
    static Rs last;
    if (f || i.s != last.s) {
      if (t.size() > tar.size()) {
        tar = t;
      }
      t.clear();
      t.emplace_back(i.l, i.r);
    } else if (t.back().second < i.l) {
      t.emplace_back(i.l, i.r);
    }
    f = 0;
    last = i;
  }
  if (t.size() > tar.size()) {
    tar = t;
  }
  cout << tar.size() << '\n';
  for (auto [l, r] : tar) {
    cout << l << ' ' << r << '\n';
  }
  return 0;
}