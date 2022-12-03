#include <iostream>

using namespace std;

int F, v;
int num[101][101], f[101][101];

inline void print(int v, int F) {
  if (F)
    for (int i = 0; i <= v - F; i++)
      if (f[v][F] == f[F + i - 1][F - 1] + num[F][F + i]) {
        print(F + i - 1, F - 1);
        cout << F + i << ' ';
        return;
      }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> F >> v;
  for (int i = 1; i <= F; i++)
    for (int j = 1; j <= v; j++)
      cin >> num[i][j];
  for (int i = 1; i <= F; i++)
    f[i][i] = f[i - 1][i - 1] + num[i][i];
  for (int i = 1; i <= v; i++)
    for (int j = 1; j <= F; j++) {
      f[i][j] = -0x7fffffff;
      for (int k = 0; k <= i - j; k++)
        f[i][j] = max(f[i][j], f[j + k - 1][j - 1] + num[j][j + k]);
    }
  cout << f[v][F] << '\n';
  print(v, F);
  return 0;
}