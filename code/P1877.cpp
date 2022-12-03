#include <iostream>
#define int long long

using namespace std;

bool vis[50][1001];
int e[50];
int n, Max, MAX = -1;

inline void dfs(int idx, int now) {
  if (now > Max or now < 0)
    return;
  if (vis[idx][now])
    return;
  vis[idx][now] = true;
  if (idx == n) {
    MAX = max(MAX, now);
    return;
  }
  dfs(idx + 1, now + e[idx]);
  dfs(idx + 1, now - e[idx]);
}

signed main() {
  ios_base::sync_with_stdio(false);
  int begin;
  cin >> n >> begin >> Max;
  for (int i = 0; i < n; i++)
    cin >> e[i];
  dfs(0, begin);
  cout << MAX;
  return 0;
}