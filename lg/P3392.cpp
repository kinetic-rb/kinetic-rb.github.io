#include <stdio.h>

int n, m, ans = 0x7fffffff;
int w[51], b[51], r[51];
char now[51];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", now);
        int tot = 0;
        for (int j = 0; j < m; j++)
            tot += now[j] != 'W';
        w[i + 1] = w[i] + tot;
        tot = 0;
        for (int j = 0; j < m; j++)
            tot += now[j] != 'B';
        b[i + 1] = b[i] + tot;
        tot = 0;
        for (int j = 0; j < m; j++)
            tot += now[j] != 'R';
        r[i + 1] = r[i] + tot;
    }
    for (int i = 1; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            ans = (ans < w[i] + b[j] - b[i] + r[n] - r[j]) ? ans : w[i] + b[j] - b[i] + r[n] - r[j];
        }
    printf("%d", ans);
    return 0;
}