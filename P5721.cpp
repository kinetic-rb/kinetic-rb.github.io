#include <iostream>

using namespace std;

int main() {
\tint n;
\tcin >> n;
\tfor (int i = n; i > 0; i--) {
\t\tstatic int now = 1;
\t\tfor (int j = 0; j < i; j++) {
\t\t\tif (j + now < 10)
\t\t\t\tcout << 0;
\t\t\tcout << j + now;
\t\t}
\t\tnow += i;
\t\tcout << '\n';
\t}
\treturn 0;
}