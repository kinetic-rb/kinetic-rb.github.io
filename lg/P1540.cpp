#include <iostream>

using namespace std;
using tp = long long;

bool vis[1005];
tp b[1005];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n, m, cnt = 0;
  cin >> m >> n;
  while (n--) {
    tp x;
    cin >> x;
    if (!vis[x]) {
      static tp r = 0;
      ++cnt;
      vis[b[++r] = x] = 1;
      if (r > m) {
        static tp l = 0;
        ++l;
        vis[b[l]] = 0;
      }
    }
  }
  cout << cnt;
  return 0;
}