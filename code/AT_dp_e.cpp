#include <iostream>

using namespace std;

int v[1001], w[1001], f[1000001];

int main() {
  int n, m, sum = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    sum += v[i];
  }
  for (int i = 1; i <= sum; i++)
    f[i] = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    for (int j = sum; j >= v[i]; j--)
    f[j] = min(f[j], f[j - v[i]] + w[i]);
  for (int i = sum; i > -1; i--)
  if (f[i] <= m) {
    cout << i;
    return 0;
  }
}