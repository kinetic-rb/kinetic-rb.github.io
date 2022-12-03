#ifdef LTBUG
#include "lib.h"
#else
#include <iostream>
#define bug(...)
#endif

using namespace std;
using vt = long long;

signed main() {
  vt cnt[2], x;
  bool i;
  cin >> cnt[0] >> cnt[1] >> x;
  for (i = cnt[1] > cnt[0]; --x; i ^= true) {
    --cnt[i];
    cout << i;
  }
  cout << string(cnt[i], i ^ 48) << string(cnt[!i], !i ^ 48);
  return 0;
}
