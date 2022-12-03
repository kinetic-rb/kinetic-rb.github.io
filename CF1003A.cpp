#ifdef LTBUG
#include "lib.h"
#else
#include <iostream>
#define bug(...)
#endif

using namespace std;
using vt = long long;
constexpr vt Hat_Rg = 103;

vt num[Hat_Rg];

signed main() {
  vt n, MAX = 0;
  cin >> n;
  while (n--) {
    vt x;
    cin >> x;
    ++num[x];
  }
  for (vt i = 0; i < Hat_Rg; ++i) {
    if (num[i] > MAX) {
      MAX = num[i];
    }
  }
  cout << MAX;
  return 0;
}