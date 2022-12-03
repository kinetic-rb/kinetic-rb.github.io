#include <iostream>

using namespace std;

int main() {
\tint n, now = 1;
\tcin >> n;
\tfor (int i = 1; i < n; i++) {
\t\tnow = ((now + 1) << 1);
\t}
\tcout << now;
\treturn 0;
}