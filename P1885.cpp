#include <iostream>
#include <algorithm>

using namespace std;

int a[25] = {3};

inline char Do(int i, int n) {
  if (!i)
    return n == 1 ? 'm' : 'o';
  if (n <= a[i - 1])
    return Do(i - 1, n);
  if (n > a[i] - a[i - 1])
    return Do(i - 1, n - a[i] + a[i - 1]);
  return n == a[i - 1] + 1 ? 'm' : 'o';
}

int main() {
  int n, l = 0;
  for (cin >> n; a[l] <= n; l++) {
    a[l + 1] = (a[l] * 2 + l + 4);
  }
  cout << Do(l, n);
  return 0;
}