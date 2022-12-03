#include <iostream>

using namespace std;

int main() {
  int a, x;
  cin >> a >> x;
  for (int i = 1; i < 0x7ffffff; i++) {
    if ((i + a - 1) * 1.0 / a >= x) {
      cout << i;
      return 0;
    }
  }
  return 0;
}