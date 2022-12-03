#include <iostream>
#include <cstring>

using namespace std;

long long p[105], c[105], f[60000];

int main() {
  memset(f, 0x3f, sizeof f);
  long long n, h, MIN = 0x7fffffff;
  cin >> n >> h;
  for (int i = 1; i <= n; i++)
    cin >> p[i] >> c[i];
  *f = 0;
  for (int i = 1; i <= n; i++)
    for (int j = p[i]; j < h + 5001; j++)
      f[j] = min(f[j], f[j - p[i]] + c[i]);
  for (int i = h; i < h + 5001; i++)
    MIN = min(MIN, f[i]);
  cout << MIN;
  return 0;
}