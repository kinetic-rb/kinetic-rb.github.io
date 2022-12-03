#include <iostream>

using namespace std;

int main() {
  long n, cnt = 0;
  for (cin >> n; n - 1; cnt++)
    n = n & 1 ? n * 3 + 1 : n >> 1;
  cout << cnt;
  return 0;
}