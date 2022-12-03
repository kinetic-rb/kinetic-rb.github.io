#include <iostream>

using namespace std;

int w[10001], c[10001], f[10001];

int main() {
    ios_base::sync_with_stdio(false);
  int  n, v;
  cin >> v >> n;
  for (int i = 0; i < n; i++)
    cin >> w[i] >> c[i];
  for (int i = 1; i <= v; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k * c[j] <= i; k++)
        f[i] = max(f[i], k * w[j] + f[i - k * c[j]]);
  cout << f[v];
  return 0;
}