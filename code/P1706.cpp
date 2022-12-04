#include <iostream>
#include <functional>

using namespace std;

int choose[15];
bool vis[15];

int main() {
  int n;
  ios_base::sync_with_stdio(false);
  cin >> n;
  function<void(int)> dfs = [&](int idx) -> void {
    if (idx == n) {
      for (int i = 0; i < n; i++)
        cout << "    " << choose[i];
      cout << '\n';
      return;
    }
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        vis[i] = true;
          choose[idx] = i;
          dfs(idx + 1);
          vis[i] = false;
      }
  };
  dfs(0);
  return 0;
}