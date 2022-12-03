#include <iostream>

using namespace std;

int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  for (double i = -100; i <= 100; i += 0.001) {
    double j = i + 0.001;
    double x = a * i * i * i + b * i * i + c * i + d;
    double y = a * j * j * j + b * j * j + c * j + d;
    if (x >= 0 && y <= 0 || x <= 0 && y >= 0) {
      printf("%.2lf ", (i + j) / 2);
    }
  }
  return 0;
}