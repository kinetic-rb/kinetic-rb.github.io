#include <stdio.h>
#define R register
#define I int

int main() {
    R I n, m, x, y, k = 0, t;
    bool flag = false;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    R I a[100][4], b[100][2];
    for (R I i = 0; i < x; i++) {
        for (R I j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (R I i = 0; i < y; i++) {
        for (R I j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (R I i = 0; i < y; i++) {
        for (R I j = 0; j < x; j++) {
            if ((b[i][0] >= a[j][0] && b[i][0] <= a[j][2]) && (b[i][1] >= a[j][1] && b[i][1] <= a[j][3])) {
                flag = true;
                k++;
                t = j + 1;
            }
        }
        (flag) ? printf("Y %d %d
", k, t) : printf("N ");
        flag = false;
        k = 0;
    }
    return 0;
}