#include <iostream>

using namespace std;

int v[1001], w[1001], f[1000001];

int main() {
\tint n, m, sum = 0;
\tcin >> n >> m;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> w[i] >> v[i];
    sum += v[i];
  }
  for (int i = 1; i <= sum; i++)
    f[i] = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    for (int j = sum; j >= v[i]; j--)
\t  f[j] = min(f[j], f[j - v[i]] + w[i]);
  for (int i = sum; i > -1; i--)
\tif (f[i] <= m) {
\t  cout << i;
\t  return 0;
\t}
}