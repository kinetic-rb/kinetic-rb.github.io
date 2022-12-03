#include <stdio.h>

int ps[500005];

int main() {
\tint n, MAX = 0;
\tscanf("%d", &n);
\tfor (register int i = 1; i <= n; i++) {
\t\tscanf("%d", ps + i);
\t\tps[i] = (ps[i] + ps[i - 1]) % 7;
\t}
\tfor (register int i = 1; i <= n; i++) {
\t\tfor (register int j = i; j <= n; j++) {
\t\t\tif (!(ps[j] - ps[i - 1])) {
\t\t\t    register int x = j - i + 1;
\t\t\t    if (x > MAX)
\t\t\t        MAX = x;
\t\t\t}
\t\t}
\t}
\tprintf("%d", MAX);
\treturn 0;
}