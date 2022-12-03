#include <iostream>

using namespace std;
using dt = long long;

signed main() {
  dt a, b, c;
  cin >> a >> b >> c;
  if (a > b)
    swap(a, b);
  if (b > c)
    swap(b, c);
  if (a > b)
    swap(a, b);
  if (a + b <= c) {
    puts("Not triangle");
    return 0;
  }
  if (a * a + b * b == c * c)
    puts("Right triangle");
  else if (a * a + b * b > c * c)
    puts("Acute triangle");
  else if (a * a + b * b < c * c)
    puts("Obtuse triangle");
  if (a == b) {
    puts("Isosceles triangle");
    if (b == c)
        puts("Equilateral triangle");
  }
  return 0;
}