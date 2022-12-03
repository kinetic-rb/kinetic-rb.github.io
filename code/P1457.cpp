#include <iostream>

using namespace std;

int n, m, s, ans;
int room[61][61][4], flag[61][61], roomsize[2600];
char position;

inline void dfs(int x, int y) {
    if (flag[x][y] || x < 1 || y < 1 || x > n || y > m)
        return;
    ans++;
    flag[x][y] = s + 1;
    if (!room[x][y][0] && !(flag[x][y + 1] != 0 || x < 1 || y < 1 || x > n || y > m))
        dfs(x, y + 1);
    if (!room[x][y][1] && !(flag[x + 1][y] != 0 || x < 1 || y < 1 || x > n || y > m))
        dfs(x + 1, y);
    if (!room[x][y][2] && !(flag[x][y - 1] != 0 || x < 1 || y < 1 || x > n || y > m))
        dfs(x, y - 1);
    if (!room[x][y][3] && !(flag[x - 1][y] != 0 || x < 1 || y < 1 || x > n || y > m))
        dfs(x - 1, y);
}

int main() {
    int maxn = 0, xx = 0, yy = 10000;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s;
            if (s & 1) room[i][j][2] = 1;
            if (s & 2) room[i][j][3] = 1;
            if (s & 4) room[i][j][0] = 1;
            if (s & 8) room[i][j][1] = 1;
        }
    }
    s = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            ans = 0;
            if (!flag[i][j]) {
                dfs(i, j);
                roomsize[++s] = ans;
            }
            maxn = max(maxn, ans);
        }
    ans = 0;
    cout << s << '\n' << maxn << '\n';
    int Max = maxn;
    for (int k = 1; k <= m; k++) {
        for (int i = n; i > 0; i = i - 1) {
            if (flag[i][k] != flag[i - 1][k]) {
                if (roomsize[flag[i][k]] + roomsize[flag[i - 1][k]] > Max) {
                    xx = i, yy = k;
                    Max = roomsize[flag[i][k]] + roomsize[flag[i - 1][k]];
                    position = 'N';
                }
            }
            if (flag[i][k] != flag[i][k + 1])
                if (roomsize[flag[i][k]] + roomsize[flag[i][k + 1]] > Max) {
                    xx = i;
                    yy = k;
                    Max = roomsize[flag[i][k]] + roomsize[flag[i][k + 1]];
                    position = 'E';
                }
        }
    }
    cout << Max << '\n' << xx << " " << yy << " " << position;
    return 0;
}