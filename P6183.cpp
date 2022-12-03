#include <stdio.h>
#define int unsigned

int mapp[70000][20];

signed main() {
\tint n, num = 2;
\tmapp[1][1] = 0;
\tmapp[2][1] = 1;
\tscanf("%d", &n);
\tfor (int i = 2; i <= n; i++) {
\t\tnum <<= 1;
\t\tfor (int j = 1; j <= (num >> 1); j++) {
\t\t\tfor (int k = 1; k < i; k++)
\t\t\t\tmapp[(num >> 1) + j][k] = mapp[(num >> 1) - j + 1][k];
\t\t}
\t\tfor (int j = 1; j <= num; j++)
\t\t\tmapp[j][i] = (j > (num >> 1));
\t}
\tfor (int i = 1; i <= num; i++) {
\t\tfor (int j = 1; j <= n; j++)
\t\t\tputchar(mapp[i][j] ? 'X' : 'O');
\t\tputchar('\n');
\t}
\tfor (int i = 0; i < n; i++)
\t\tputchar('O');
\treturn 0;
}