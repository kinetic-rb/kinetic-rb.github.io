#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((a < 60) + (b < 60) + (c < 60) == 1);
  return 0;
}