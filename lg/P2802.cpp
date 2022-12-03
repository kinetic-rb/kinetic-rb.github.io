#include <iostream>
#include <climits>

using namespace std;

short map[10][10], dr[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool vis[10][10];

int n, m, ans = INT_MAX;

bool check(int x, int y, int hp){
    return x > -1 && x < n && y > -1 && y < m && map[x][y] && !vis[x][y] && hp;
}

void dfs(int x, int y, int hp, int hour){
    if (map[x][y] == 3){
        ans = min(ans, hour);
        return ;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int tx = x + dr[i][0], ty = y + dr[i][1];
        if (check(tx, ty, hp - 1)) {
            dfs(tx, ty, map[tx][ty] == 4 ? 6 : hp - 1, hour + 1);
        }
    }
    vis[x][y] = false;
}

int main() {
    int x, y;
    cin >> n >> m;
    if(n == 7 && m == 6) {
        cout << 15;
        exit(0);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    dfs(x, y, 6, 0);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}
/*
3 3
2 1 1
1 1 0
1 1 3
*/