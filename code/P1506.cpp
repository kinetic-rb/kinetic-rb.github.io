#include <iostream>
#include <algorithm>

using namespace std;

char b[505][505];
const int dr[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m;

inline void dfs(int x, int y) {
    for (auto i : dr) {
        int dx = x + i[0], dy = i[1] + y;
        if (min(dx, dy) > -1 && dx < n + 2 && dy < m + 2 && b[dx][dy] != '*') {
            b[dx][dy] = '*';
            dfs(dx, dy);
        }
    }
}

int main() {
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < 505; i++)
        for (int j = 0; j < 505; j++)
            b[i][j] = '#';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    dfs(0, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (b[i][j] == '0')
                cnt++;
    cout << cnt;
    return 0;
}