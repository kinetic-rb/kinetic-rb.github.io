#include <algorithm>
#include <iostream>

using namespace std;

struct CE {
  int h, a, c;
  inline bool operator<(const CE& comp) const {
    return a < comp.a;
  }
} e[405];

bool f[405][40005];

int main() {
  **f = true;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> e[i].h >> e[i].a >> e[i].c;
  stable_sort(e + 1, e + n + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 40001; j++) {
      f[i][j] |= f[i - 1][j];
      for (int k = 1; k <= e[i].c; k++)
        if (j <= e[i].a && j >= e[i].h * k)
          f[i][j] |= f[i - 1][j - e[i].h * k];
    }
  for (int i = 40000; i > -1; i--)
    if (f[n][i]) {
      cout << i;
      return 0;
    }
  return 0;
}