#include <iostream>
#include <cmath>

using namespace std;

int au[1000000], f[1000000];

int main() {
  int m, n;
  cin >> m;
  for (int i = 1; i <= m; i++)
    f[i] = 0x7fffffff;
  n = ceil(sqrt(sqrt(m))) + 2;
  for (int i = 1; i < n; i++)
    au[i] = i * i * i * i;
  for (int i = 1; i < n; i++)
    for (int j = au[i]; j <= m; j++)
      f[j] = min(f[j], f[j - au[i]] + 1);
  cout << f[m];
  return 0;
}