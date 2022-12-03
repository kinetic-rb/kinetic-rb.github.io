#include <bits/stdc++.h>

using namespace std;

struct place{
    int x, y;
} Place;

const int M = 32;
int map1[M][M], visited[M][M], dx[4]={1, -1, 0, 0}, dy[4]={0, 0, -1, 1};
int n;

queue <place> q;

void bfs(int x,int y) {
    visited[x][y] = 1;
    Place.x = x;
    Place.y = y;
    for (q.push(Place); !q.empty(); ) {
        place A = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int zx, zy;
            zx = A.x + dx[i];
            zy = A.y + dy[i];
            if (zx < 0 || zx > n + 1 || zy < 0 || zy > n + 1 || visited[zx][zy])
                continue;
            visited[zx][zy] = 1;
            struct place B;
            B.x = zx;
            B.y = zy;
            q.push(B);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map1[i][j];
            if (map1[i][j] == 0)
                visited[i][j] = 0;
            else
                visited[i][j] = 1;
        }
    }
    bfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) cout << "2" << " ";
            else cout << map1[i][j] << " ";;
        }
        cout << '\n';
    }
    return 0;
}