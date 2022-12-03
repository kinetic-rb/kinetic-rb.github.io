#include <stdio.h>

int main() {
\tint n, m, sum = 0, cnt = 1;
\tscanf("%d%d", &n, &m);
\tfor (int i = 0; i < n; i++) {
\t\tint x;
\t\tscanf("%d", &x);
\t\tsum += x;
\t\tif (sum > m) {
\t\t\tcnt++;
\t\t\tsum = x;
\t\t}
\t}
\tprintf("%d", cnt);
\treturn 0;
}