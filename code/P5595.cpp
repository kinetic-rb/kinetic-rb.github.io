#include <iostream>
#include <cmath>

using namespace std;

int main() {
  string c, x, y;
  int X = 0, Y = 0, loc;
  cin >> c;
  for (loc = c.size() - 1; c[loc] == 'Z' && loc > -1; loc--);
  for (; loc > -1; loc--)
    if (c[loc] == 'Z') {
      cout << -1;
      return 0;
    }
  for (int i = 0; i < c.size(); i++) {
    if (c[i] == 'X') {
      x.push_back('9');
      y.push_back('1');
    } else if (c[i] == 'Y') {
      y.push_back('9');
      x.push_back('1');
    } else {
      x.push_back('5');
      y.push_back('5');
    }
  }
  cout << x << '\n' << y;
  return 0;
}