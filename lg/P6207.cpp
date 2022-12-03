#include <iostream>

using namespace std;

bool mz[120][80];
int getwa[100000][2], dr[][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int n, m, step;

void dfs(int, int);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            mz[i][j] = c == '.';
        }
    dfs(0, 0);
    return 0;
}

inline void dfs(int x, int y) {
    if (x + 1 == n && y + 1 == m) {
        cout << "1 1
";
        for (int i = 0; i < step; i++)
            cout << ++getwa[i][0] << ' ' << ++getwa[i][1] << '\n';
        exit(0);
    }
    for (auto i : dr) {
        int dx = x + i[0], dy = i[1] + y;
        if (min(dx, dy) > -1 && dx < n && dy < m && mz[dx][dy]) {
            getwa[step][0] = dx;
            getwa[step++][1] = dy;
            mz[dx][dy] = false;
            dfs(dx, dy);
            mz[dx][dy] = true;
            step--;
        }
    }
}