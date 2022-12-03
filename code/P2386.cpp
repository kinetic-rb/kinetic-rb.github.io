#include <iostream>

using namespace std;

int m, n, cnt;

inline void dfs(int idx, int sum, int last) {
  if (idx == n) {
    if (sum == m)
      cnt++;
    return;
  }
  for (int i = last; i + sum <= m; i++)
    dfs(idx + 1, sum + i, i);
}

int main() {
  int t;
  for (cin >> t; t--; cnt = 0) {
    cin >> m >> n;
    dfs(0, 0, 0);
    cout << cnt << '\n';
  }
  return 0;
}