#include <iostream>

using namespace std;

int n, k, cnt;

inline void dfs(int idx = 0, int last = 1, int sum = 0) {
  if (idx == k) {
    if (sum == n)
      cnt++;
    return;
  }
  for (int i = last; i <= n && sum + i <= n; i++)
    dfs(idx + 1, i, sum + i);
}

int main() {
  cin >> n >> k;
  dfs();
  cout << cnt;
  return 0;
}