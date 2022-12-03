#include <iostream>

using namespace std;

long f[1001];
bool b[1001];

int main() {
  int n;
  for (int i = 2; i < 500; i++)
    if (!b[i])
      for (int j = 2; i * j <= 1001; j++)
        b[i * j] = 1;
  cin >> n;
  *f = 1;
  for (int i = 2; i <= n; i++)
    if (!b[i])
      for (int j = i; j <= n; j++)
        f[j] += f[j - i];
  cout << f[n];
    return 0;
}