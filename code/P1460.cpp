#include <iostream>

using namespace std;

int sum[101], need[101], s[101][101], r[101], o[101];
int n, k, MIN = 0x7fffffff, ans;

inline void dfs(int idx) {
  bool l = true;
  for (int i = 1; i <= n; i++) {
    if (sum[i] < need[i]) {
      l = false;
      break;
    }
  }
  if (l) {
    if (ans < MIN) {
      MIN = ans;
      for (int i = 1; i <= MIN; i++)
        r[i] = o[i];
    }
    return;
  }
  o[++ans] = idx;
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i] + s[idx][i];
  for (int i = 1; i <= k - idx + 1; i++)
    dfs(idx + i);
  ans--;
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i] - s[idx][i];
}

int main() {
    ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> need[i];
  cin >> k;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++)
      cin >> s[i][j];
  dfs(0);
  cout << MIN - 1 << ' ';
  for (int i = 2; i <= MIN; i++)
    cout << r[i] << ' ';
  return 0;
}