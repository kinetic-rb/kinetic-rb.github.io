#ifdef NDEBUG
#define BUG 1
#include "lib.h"
#else
#include <iostream>
#define bug(...)
#endif

using vt = long long;
using uvt = unsigned long long;
using namespace std;

vt m[3500003], b[3500003], p[3500003];
string s;

void Calc(uvt i) {
  m[i] = m[i - 1] * 13331 - s[i] - 96;
  b[i] = b[i - 1] * 13331 - s[s.size() - i] - 96;
  p[i] = p[i - 1] * 13331;
}

vt GetB(vt l, vt r) {
  return b[r] - b[l - 1] * p[r - l + 1];
}

bool h(vt l, vt r) {
  return m[r] - m[l - 1] * p[r - l + 1] == GetB(s.size() - r, s.size() - l);
}

signed main() {
  vt t, cnt = 0;
  cin.putback('\a');
  cin >> s >> t;
  *p = 1;
  for (uvt i = 1; i < s.size(); ++i) {
    Calc(i);
  }
  for (vt l, r; t--; cout << (h(l, r) ? 'Y' : 'N')) {
    cin >> l >> r;
  }
  return 0;
}