#include <iostream>
#include <cmath>

using namespace std;

int main() {
\tdouble a, b, c, x1, x2, delta;
\tcin >> a >> b >> c;
\tdelta = b * b - 4 * a * c;
\tif (delta < 0 && fabs(delta) > 1e-12) {
\t\tprintf("No answer!");
\t\treturn 0;
\t}
\tif (fabs(delta) < 1e-12) {
\t\tx1 = -b / (2 * a);
\t\t(fabs(x1) < 1e-6) ? printf("x1=x2=0.00000") : printf("x1=x2=%.5lf", x1);
\t\treturn 0;
\t}
\tx1 = (-b + sqrt(delta)) / (2 * a);
\tx2 = (-b - sqrt(delta)) / (2 * a);
\tif (fabs(x1) < 1e-6)
\t\tx1 = fabs(x1);
\tif (fabs(x2) < 1e-6)
\t\tx2 = fabs(x2);
\tprintf("x1=%.5lf;x2=%.5lf", min(x1, x2), max(x1, x2));
\treturn 0;
}