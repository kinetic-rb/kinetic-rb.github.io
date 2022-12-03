#include <iostream>
#define int long long

using namespace std;

int b[101];

signed main() {
  int n, m, MAX = -0x7fffffff;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (i != j and j != k and i != k and b[i] + b[j] + b[k] <= m and
            b[i] + b[j] + b[k] > MAX)
          MAX = b[i] + b[j] + b[k];
  cout << MAX;
  return 0;
}