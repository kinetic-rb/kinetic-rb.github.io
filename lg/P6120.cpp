#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 1e5 + 3;

tp ph[Hat_N], pp[Hat_N], ps[Hat_N], sh[Hat_N], sp[Hat_N], ss[Hat_N];

signed main() {
  tp n, MAX = 0;
  string s;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    s.push_back(c);
    ph[i] = ph[i - 1] + (c == 'H');
    pp[i] = pp[i - 1] + (c == 'P');
    ps[i] = ps[i - 1] + (c == 'S');
  }
  for (tp i = n; i; --i) {
    sh[i] = sh[i + 1] + (s[i] == 'H');
    sp[i] = sp[i + 1] + (s[i] == 'P');
    ss[i] = ss[i + 1] + (s[i] == 'S');
  }
  for (tp i = 0; i <= n; ++i) {  // [1, i] (i, n]
    MAX = max(MAX, max(max(ph[i], pp[i]), ps[i]) + max(max(sh[i], sp[i]), ss[i]));
  }
  cout << MAX;
  return 0;
}