#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  for (double i = -100; i <= 100; i += 0.001) {
    double j = i + 0.001, x = a * i * i * i + b * i * i + c * i + d, y = a * j * j * j + b * j * j + c * j + d;
    if (x >= 0 && y <= 0 or x <= 0 && y >= 0)
      cout << fixed << setprecision(2) << (i + j) / 2 << ' ';
  }
  return 0;
}