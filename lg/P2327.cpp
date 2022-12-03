#include <iostream>

using namespace std;

bool a[10005];
int b[10005];
int n, ans;

inline bool pd(int x) {
  if (a[x - 1] + a[x] + a[x + 1] == b[x])
    return true;
  return false;
}

inline void dfs(int k) {
  if (k == n + 1) {
    if (pd(n))
      ans++;
    return;
  }
  a[k] = true;
  if (k == 1 || pd(k - 1))
    dfs(k + 1);
  a[k] = false;
  if (k == 1 || pd(k - 1))
    dfs(k + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  dfs(1);
  cout << ans;
  return 0;
}