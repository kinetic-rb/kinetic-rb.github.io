#include <iostream>
#include <cstring>

using namespace std;

int main() {
\tbool t[10], no = true;
\tint x = 100, y = 100, z = 100, tx, ty, tz, A, B, C;
\tint s[9];
\tcin >> A >> B >> C;
\tfor (; x < 1000; x++)
\t\tfor (y = 100; y < 1000; y++)
\t\t\tfor (z = 100; z < 1000; z++) {
\t\t\t\ttx = x * B * C;
\t\t\t\tty = y * A * C;
\t\t\t\ttz = z * A * B;
\t\t\t\tif (tx == ty)
\t\t\t\t\tif (ty == tz)
\t\t\t\t\t\tif (tx == ty)
\t\t\t\t\t\t\tif (ty == tz) {
\t\t\t\t\t\t\t\tmemset(t, false, sizeof(t));
\t\t\t\t\t\t\t\tt[x % 10 - 1] = t[x / 10 % 10 - 1] = t[x / 100 - 1] = t[y % 10 - 1] = t[y / 10 % 10 - 1] = t[y / 100 - 1] = t[z % 10 - 1] = t[z / 10 % 10 - 1] = t[z / 100 - 1] = true;
\t\t\t\t\t\t\t\tif (t[0] && t[1] && t[2] && t[3] && t[4] && t[5] && t[6] && t[7] && t[8]) {
\t\t\t\t\t\t\t\t\tcout << x << " " << y << " " << z << '\n';
\t\t\t\t\t\t\t\t\tno = false;
\t\t\t\t\t\t\t\t}
\t\t\t\t\t\t\t}
\t\t\t}
\tif (no)
\t\tcout << "No!!!";
\treturn 0;
}