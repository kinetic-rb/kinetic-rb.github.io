#include <cstring>
#include <iostream>

using namespace std;

int f[100005], num[100005];

int main() {
  memset(f, 0x3f, sizeof f);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  f[1] = 0;
  for (int i = 2; i <= n; i++)
    for (int j = i - 1; j >= max(1, i - k); j--)
      f[i] = min(f[i], f[j] + abs(num[j] - num[i]));
  cout << f[n];
  return 0;
}