#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double a, b, c, x1, x2, delta;
  cin >> a >> b >> c;
  delta = b * b - 4 * a * c;
  if (delta < 0 && fabs(delta) > 1e-12) {
    printf("No answer!");
    return 0;
  }
  if (fabs(delta) < 1e-12) {
    x1 = -b / (2 * a);
    (fabs(x1) < 1e-6) ? printf("x1=x2=0.00000") : printf("x1=x2=%.5lf", x1);
    return 0;
  }
  x1 = (-b + sqrt(delta)) / (2 * a);
  x2 = (-b - sqrt(delta)) / (2 * a);
  if (fabs(x1) < 1e-6)
    x1 = fabs(x1);
  if (fabs(x2) < 1e-6)
    x2 = fabs(x2);
  printf("x1=%.5lf;x2=%.5lf", min(x1, x2), max(x1, x2));
  return 0;
}