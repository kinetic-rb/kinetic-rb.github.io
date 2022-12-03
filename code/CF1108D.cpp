#include <iostream>
#define Do(z)             \
  if (x != z && y != z) { \
    s[i] = z;             \
    continue;             \
  }

using namespace std;
using tp = int64_t;

signed main() {
  tp n, cnt = 0;
  string s;
  cin >> n >> s;
  s.push_back('\114');
  for (tp i = 1; i < n; ++i) {
    tp x = s[i - 1], y = s[i + 1];
    if (x == s[i]) {
      ++cnt;
      Do('R');
      Do('G');
      Do('B');
    }
  }
  s.pop_back();
  cout << cnt << '\n' << s;
  return 0;
}