#include <cstdint>
#include <cstring>
#include <iostream>
#define plus(x, y) x = (x + y) % _MOD_

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 403, _MOD_ = 1e9 + 7;

tp n, m;
string s, t;
tp f[Hat_N][Hat_N][Hat_N];

tp dfs(tp i = 0, tp j = 0, tp k = 0, tp l = 0) {
  if (i == n) {
    return j == m && !k && !l;
  }
  if (~f[i][j][k]) {
    return f[i][j][k];
  }
  if (s[i] == '-') {
    f[i][j][k] = 0;
    if (k) {
      plus(f[i][j][k], dfs(i + 1, j, k - 1, l));
    }
    if (l) {
      plus(f[i][j][k], dfs(i + 1, j, k, l - 1));
    }
  } else {
    f[i][j][k] = dfs(i + 1, j, k, l + 1);
    if (!j && !l) {
      plus(f[i][j][k], dfs(i + 1, 0, k + 1, 0));
    }
    if (s[i] == t[j] && !l) {
      plus(f[i][j][k], dfs(i + 1, j + 1, k, 0));
    }
  }
  return f[i][j][k];
}

void Core() {
  cin >> n >> m >> s >> t;
  memset(f, -1, sizeof f);
  cout << dfs() << '\n';
}

signed main() {
  tp __TESTS__;
  cin >> __TESTS__;
  while (__TESTS__--) {
    Core();
  }
  return 0;
}