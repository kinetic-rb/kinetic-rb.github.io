#include <iostream>
#include <string>

using namespace std;

int main() {
\tstring x;
\tlong long n, lx;
\tcin >> x >> n;
\tlx = x.length();
\tint m = 0;
\twhile (n > lx) {
\t\tlx <<= 1;
\t\tm++;
\t}
\tfor (int i = 0; i < m; i++) {
\t\tlx >>= 1;
\t\tif (n <= lx) {
\t\t\tcontinue;
\t\t}
\t\t(n == lx + 1) ? n = lx : n -= (lx + 1);
\t}
\tcout << x[n - 1];
\treturn 0;
}