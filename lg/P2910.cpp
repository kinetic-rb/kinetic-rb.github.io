#include <stdio.h>

int dis[101][101], num[10001];

int main() {
\tint n, m, ans = 0;
\tscanf("%d%d", &n, &m);
\tm++;
\tn++;
\tfor (register int i = 1; i < m; i++)
\t\tscanf("%d", num + i);
\tfor (register int i = 1; i < n; i++)
\t\tfor (register int j = 1; j < n; j++)
\t\t\tscanf("%d", &dis[i][j]);
\tfor (register int k = 1; k < n; k++)
\t\tfor (register int i = 1; i < n; i++)
\t\t\tfor (register int j = 1; j < n; j++)
\t\t\t\tif (dis[i][k] + dis[k][j] < dis[i][j])
\t\t\t\t\tdis[i][j] = dis[i][k] + dis[k][j];
\tfor (register int i = 2; i < m; i++)
\t\tans += dis[num[i - 1]][num[i]];
\tprintf("%d", ans);
\treturn 0;
}