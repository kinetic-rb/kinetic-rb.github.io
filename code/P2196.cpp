#include <iostream>
#include <algorithm>

using namespace std;

bool l[205][205];
int f[205], num[205];
int way[205];

inline void so(int u) {
  if (!way[u]) {
    cout << u;
    return;
  }
  so(way[u]);
  cout << ' ' << u;
}

int main() {
  int n, MAX = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    f[i] = num[i];
  }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      bool h;
      cin >> h;
      if (h)
        l[i][j] = true;
    }
  for (int s = 1; s <= n; s++)
    for (int i = 1; i <= n; i++)
      if (l[i][s])
        if (f[i] + num[s] > f[s]) {
          f[s] = f[i] + num[s];
          way[s] = i;
        }
  MAX = max_element(f + 1, f + n + 1) - f;
  so(MAX);
  cout << '\n' << f[MAX];
  return 0;
}