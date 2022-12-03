#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    int x;
    cin >> x;
    puts(x % 2020 > x / 2020 ? "nO" : "yEs");
  }
  return 0;
}