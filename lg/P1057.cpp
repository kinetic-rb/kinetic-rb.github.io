#include <stdio.h>

int people[30][30] = {1};

int main() {
    short n, m;
    scanf("%d%d", &n, &m);
    for (short i = 0; i < m; i++) {
        for (short j = 0; j < n; j++) {
            people[j][i + 1] += people[(j + n + 1) % n][i] + people[(j + n - 1) % n][i];
        }
    }
    printf("%d", people[0][m]);
    return 0;
}