#include <iostream>
#define int long long

using namespace std;

int num[3003], f[50005] = {1};

signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  for (int i = 0; i < n; i++)
    for (int j = num[i]; j <= m; j++)
      f[j] += f[j - num[i]];
  cout << f[m];
  return 0;
}