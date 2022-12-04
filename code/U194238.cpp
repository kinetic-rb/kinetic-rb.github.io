#ifdef NDEBUG
#define BUG 1
#include "lib.h"
#else
#include <iostream>
#define bug(...)
#endif

using vt = long long;
using namespace std;

string x;

bool IH(vt l, vt r) {
  if (r - l < 1) {
    return true;
  }
  return x[l] == x[r] && IH(l + 1, r - 1);
}

signed main() {
  cin.tie(0);
  vt t;
  cin.putback('a');
  cin >> x >> t;
  while (t--) {
    vt l, r;
    cin >> l >> r;
    cout << (IH(l, r) ? 'Y' : 'N');
  }
  return 0;
}