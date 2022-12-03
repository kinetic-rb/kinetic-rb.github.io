#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int kMaxN = 13;

struct E {
  int x, y;
  int p, r;
  bool operator<(const E& e) const { return y < e.y || (y == e.y && x < e.x); }
} e[kMaxN];
bool b[kMaxN];
int n, ans;

inline bool C() {
  for (int i = 1; i <= n; i++) {
    memset(b, 0, sizeof b);
    for (int j = i; j; j = e[e[j].p].r) {
      if (b[j])
        return true;
      b[j] = true;
    }
  }
  return false;
}

inline void dfs(int x) {
  if (x > n) {
    if (C())
      ans++;
    return;
  }
  if (e[x].p) {
    dfs(x + 1);
    return;
  }
  for (int i = x + 1; i <= n; i++)
    if (!e[i].p) {
      e[i].p = x;
      e[x].p = i;
      dfs(x + 1);
      e[i].p = e[x].p = 0;
    }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> e[i].x >> e[i].y;
  stable_sort(e + 1, e + 1 + n);
  for (int i = 1; i < n; i++)
    e[i].r = e[i + 1].y == e[i].y ? i + 1 : 0;
  dfs(1);
  cout << ans;
  return 0;
}