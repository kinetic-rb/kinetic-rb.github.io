#include <iostream>

using namespace std;

int main() {
  unsigned long long au = 1;
  short n;
  cin >> n;
  for (short i = 2; i <= n; i++) {
    au *= i;
  }
  cout << au;
  return 0;
}