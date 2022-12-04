#include <iostream>

using namespace std;

int main() {
    int n, m, x, y, k = 0, t;
    bool flag = false;
    cin >> n >> m >> x >> y;
    int a[100][4], b[100][2];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
    for (int i = 0; i < y; i++)
        for (int j = 0; j < 2; j++)
            cin >> b[i][j];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            if ((b[i][0] >= a[j][0] && b[i][0] <= a[j][2]) && (b[i][1] >= a[j][1] && b[i][1] <= a[j][3])) {
                flag = true;
                k++;
                t = j + 1;
            }
        (flag) ? printf("Y %d %d
", k, t) : printf("N ");
        flag = false;
        k = 0;
    }
    return 0;
}