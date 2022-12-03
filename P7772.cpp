#include <iostream>

using namespace std;

int main() {
\tint a, x;
\tcin >> a >> x;
\tfor (int i = 1; i < 0x7ffffff; i++) {
\t\tif ((i + a - 1) * 1.0 / a >= x) {
\t\t\tcout << i;
\t\t\treturn 0;
\t\t}
\t}
\treturn 0;
}