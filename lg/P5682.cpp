#include <algorithm>
#include <iostream>

using namespace std;

int a[200005];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  n = unique(a + 1, a + 1 + n) - a - 1;
  printf("%d", n < 2 ? -1 : max(a[n - 2], a[n] % a[n - 1]));
  return 0;
}