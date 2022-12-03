#include <iostream>
#define int unsigned
#define DEBUG 0

inline void FileSwitch(const char* InputFileName, const char* OutputFileName) {
#if DEBUG
  freopen(InputFileName, "r", stdin);
#endif
#if DEBUG == 2
  freopen(OutputFileName, "w", stdout);
#endif
}

using namespace std;

int num[300], f[300][300];

signed main() {
  FileSwitch("^", "#");
  int n, MAX = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    num[i + n] = num[i];
    f[i][i] = num[i];
    f[i + n][i + n] = num[i];
  }
  n <<= 1;
  for (int len = 3; len <= n; len++)
    for (int l = 1; l <= n - len + 1; l++) {
      int r = l + len - 1;
      for (int k = l + 1; k < r; k++)
        f[l][r] = max(f[l][r], f[l][k] + f[k][r] + num[l] * num[r] * num[k]);
    }
  for (int i = 1; i <= n; i++)
    MAX = max(MAX, f[i][i + n - 1]);
  cout << (MAX >> 1);
  return 0;
}