#include <iostream>

using namespace std;

int main() {
\tint n;
\tcin >> n;
\tcout << (not (n bitand 1) and n > 4 and n <= 12) << ' ' << ((not (n bitand 1)) or (n > 4 and n <= 12)) << ' ' << ((not (n bitand 1)) xor (n > 4 and n <= 12)) << ' ' << ((n bitand 1) and not (n > 4 and n <= 12));
\treturn 0;
}