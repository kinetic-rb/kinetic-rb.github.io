#include <cstring>
#include <iostream>
#define Sum(s, e) ps[e] - ps[s - 1]

using namespace std;

int ps[505], num[505], f[505][505];
pair <int, int> re[505];

int main() {
  memset(f, 127, sizeof f);
  int m, k;
  cin >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> num[i];
    ps[i] = ps[i - 1] + num[i];
    f[i][0] = 0;
  }
  **f = 0;
  for (int i = 1; i <= k; i++)
    for (int j = i; j <= m; j++)
      for (int x = i; x <= j; x++)
        if (max(f[i - 1][x - 1], Sum(x, j)) < f[i][j])
          f[i][j] = max(f[i - 1][x - 1], Sum(x, j));
  for (int i = m, e = m, sum = 0, t = k; i > -1; i--) {
    sum += num[i];
    if (sum > f[k][m] || !i) {
      re[--t] = make_pair(i + 1, e);
      e = i;
      sum = num[i];
    }
  }
  for (int i = 0; i < k; i++)
    cout << re[i].first << ' ' << re[i].second << '\n';
  return 0;
}