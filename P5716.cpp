#include <stdio.h>

const int y[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
\tint x, z;
\tscanf("%d%d", &x, &z);
\tif (z == 2 && ((!(x % 4) && (x % 100)) || (!(x % 400)))) {
\t\tprintf("29");
\t\treturn 0;
\t}
\tprintf("%d", y[--z]);
\treturn 0;
}