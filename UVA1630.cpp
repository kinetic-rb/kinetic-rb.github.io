#include <cstring>
#include <iostream>
#include <string>

using namespace std;
using dt = long long;
constexpr dt Hat_N = 103;

dt f[Hat_N][Hat_N];
string res[Hat_N][Hat_N];

string s;

void check(dt l, dt r, dt i) {
  for (dt j = l; j <= r; ++j)
    if (s[j] != s[(j - l) % i + l])
      return;
  auto temp = f[l][l + i - 1] + to_string((r - l + 1) / i).size() + 2;
  if (temp < f[l][r]) {
    f[l][r] = temp;
    res[l][r] = to_string((r - l + 1) / i) + '(' + res[l][l + i - 1] + ')';
  }
}

signed main() {
  while (cin >> s) {
    memset(f, 0x3f, sizeof f);
    s = ' ' + s;
    dt n = s.size();
    for (dt i = 1; i <= n; ++i) {
      f[i][i] = 1;
      res[i][i] = s[i];
    }
    for (dt len = 1; len <= n; ++len) {
      for (dt l = 1; l + len <= n; ++l) {
        dt r = l + len;
        for (dt i = l; i < r; ++i) {
          if (f[l][i] + f[i + 1][r] < f[l][r]) {
            f[l][r] = f[l][i] + f[i + 1][r];
            res[l][r] = res[l][i] + res[i + 1][r];
          }
        }
        for (dt i = 1; i <= len; ++i) {
          if (!((r - l + 1) % i)) {
            check(l, r, i);
          }
        }
      }
    }
    res[1][n].pop_back();
    cout << res[1][n] << '\n';
  }
  return 0;
}