#include <iostream>
#include <algorithm>

using namespace std;

long long sum[1005], a[1005];
long long MAX, n, c;

inline void dfs(int n, long long x) {
  if (x > c)
    return;
  if (sum[n - 1] + x <= c) {
    MAX = max(MAX, sum[n - 1] + x);
    return;
  }
  MAX = max(MAX, x);
  for (int i = 0; i < n; i++)
    dfs(i, x + a[i]);
  return;
}

int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  dfs(n, 0);
  cout << MAX;
  return 0;
}