#include <iostream>
#include <string>

using namespace std;

int main() {
  string x;
  long long n, lx;
  cin >> x >> n;
  lx = x.length();
  int m = 0;
  while (n > lx) {
    lx <<= 1;
    m++;
  }
  for (int i = 0; i < m; i++) {
    lx >>= 1;
    if (n <= lx) {
      continue;
    }
    (n == lx + 1) ? n = lx : n -= (lx + 1);
  }
  cout << x[n - 1];
  return 0;
}