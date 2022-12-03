#include <stdio.h>
#include <stdlib.h>
#define int unsigned

int n, k;
int cho[13], b[24][24] = {1};
int vis[13];

void gob(int);
inline void gob(int n) {
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = 1; j <= i; j++)
\t\t\tb[i][j] = b[i - 1][j - 1] + b[i - 1][j];
}

int SUM();
inline int SUM() {
\tint sum = 0;
\tfor (int i = 0; i < n; i++)
\t\tsum += cho[i] * b[n][i + 1];
\treturn sum;
}

void dfs(int);
inline void dfs(int idx) {
\tif (idx == n) {
\t\tif (SUM() == k) {
\t\t\tfor (int i = 0; i < n; i++)
\t\t\t    printf("%d ", cho[i]);
\t\t\texit(0);
\t\t}
\t\treturn;
\t}
\tfor (int i = 1; i <= n; i++)
\t\tif (!vis[i]) {
\t\t\tvis[i] = 1;
\t\t\tcho[idx] = i;
\t\t\tdfs(idx + 1);
\t\t\tvis[i] = 0;
\t\t}
}

signed main() {
    scanf("%d%d", &n, &k);
\tgob(n);
\tdfs(0);
\treturn 0;
}