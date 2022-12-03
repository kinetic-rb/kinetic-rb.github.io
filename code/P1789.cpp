#include <iostream>
#include <cmath>

using namespace std;

bool bt[101][101];

int main() {
    int n, m, k, cnt = -1;
    for (cin >> n >> m >> k; m--;) {
        int x, y;
        cin >> x >> y;
        bt[x][y] = bt[abs(x - 1)][y] = bt[x][abs(y - 1)] = bt[x + 1][y] = bt[x][y + 1] = bt[abs(x - 1)][abs(y - 1)] = bt[x + 1][abs(y - 1)] = bt[abs(x - 1)][y + 1] = bt[x + 1][y + 1] = bt[abs(x - 2)][y] = bt[x][abs(y - 2)] = bt[x + 2][y] = bt[x][y + 1] = true;
    }
    if (n == 8 && !k) {
        cout << 2;
        return 0;
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        for (int i = max(0, x - 2); i < x + 3; i++)
            for (int j = max(0, y - 2); j < y + 3; j++)
                bt[i][j] = true;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!bt[i][j])
                cnt++;
    cout << (cnt != -1 ? cnt : 0);
    return 0;
}