#include <iostream>

using namespace std;

int main() {
  int n, cnt = 0;
  for (cin >> n; n; cnt++)
    n /= 2;
  cout << cnt;
  return 0;
}