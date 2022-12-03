#include <cmath>
#include <iostream>

using namespace std;

int f[100005], num[100005];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  f[2] = abs(num[2] - num[1]);
  for (int i = 3;i <= n;i++)
    f[i] = min(f[i - 1] + abs(num[i] - num[i - 1]),f[i - 2] + abs(num[i] - num[i - 2]));
  cout << f[n];
  return 0;
}