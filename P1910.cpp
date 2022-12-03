#include <iostream>

using namespace std;

struct CE {
    int x, y, c;
} b[1001];

int f[1001][1001];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> i[b].c >> i[b].x >> i[b].y;
    for (int i = 0; i < n; i++)
        for (int vx = m; vx >= i[b].x; vx--)
            for (int vy = k; vy >= i[b].y; vy--)
                f[vx][vy] = max(f[vx][vy], f[vx - i[b].x][vy - i[b].y] + i[b].c);
    cout << f[m][k];
    return 0;
}