#ifdef LOCAL_DEBUG
#include "lib.h"
#else
#include <iostream>
#define bug(...)
#endif
#include <bitset>

using namespace std;
using vt = int;
constexpr vt Hat_Slen = 1027;

bitset<Hat_Slen> s;

void dfs(vt l, vt r) {
  if (l == r) {
    cout << (s[l] ? 'I' : 'B');
  } else {
    dfs(l, l + r >> 1);
    dfs((l + r >> 1) + 1, r);
    bool B = true, I = true;
    for (vt i = l; i <= r; ++i) {
      if (s[i]) {
        B = false;
      } else {
        I = false;
      }
    }
    cout << (B ? 'B' : I ? 'I' : 'F');
  }
}

signed main() {
  vt n, m;
  cin >> n;
  m = 1 << n;
  for (vt i = 1; i <= m; ++i) {
    char c;
    cin >> c;
    s[i] = c ^ 48;
  }
  dfs(1, m);
  return 0;
}