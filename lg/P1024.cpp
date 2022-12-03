#include <iostream>

using namespace std;

int main() {
\tdouble a, b, c, d;
\tcin >> a >> b >> c >> d;
\tfor (double i = -100; i <= 100; i += 0.001) {
\t\tdouble j = i + 0.001;
\t\tdouble x = a * i * i * i + b * i * i + c * i + d;
\t\tdouble y = a * j * j * j + b * j * j + c * j + d;
\t\tif (x >= 0 && y <= 0 || x <= 0 && y >= 0) {
\t\t\tprintf("%.2lf ", (i + j) / 2);
\t\t}
\t}
\treturn 0;
}