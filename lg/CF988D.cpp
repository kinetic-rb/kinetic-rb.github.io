#include <iostream>
#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "lib.h"
#else
#define bug(...)
#endif

using namespace std;
using vt = long long;
constexpr vt Hat_N = 200003;

vt num[Hat_N];
unordered_set<vt> exist;

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n, start, tolerance, MAX = 1;
  cin >> n >> *num;
  exist.insert(*num);
  start = *num;
  for (vt i = 1; i < n; ++i) {
    cin >> num[i];
    exist.insert(num[i]);
  }
  for (vt i = 0; i < n; ++i) {
    for (vt pow = 1; num[i] + pow < 0x3f3f3f3f; pow <<= 1) {
      if (exist.count(num[i] + pow)) {
        if (2 + exist.count(num[i] + (pow << 1)) > MAX) {
          MAX = 2 + exist.count(num[i] + (pow << 1));
          start = num[i];
          tolerance = pow;
        }
        bug(pow);
      }
    }
    bug(MAX);
  }
  bug(tolerance);
  cout << MAX << '\n' << start;
  for (vt i = 1; i < MAX; ++i) {
    cout << ' ' << start + tolerance * i;
  }
  return 0;
}