#include <iostream>
#include <cstring>

using namespace std;

char map[105][105];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int co(int cnt, int i, int j) {
    for(int k = 0; k < 8; k++) {
        if(map[i + dx[k]][j + dy[k]] == '*')
            cnt++;
    }
    return cnt;
}

int main() {
    memset(map, '#', sizeof(map));
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> map[i][j];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j] == '*') {
                cout << "*";
                continue;
            }
            int cnt = 0;
            cout << co(cnt, i, j);
        }
        cout << endl;
    }
    return 0;
}