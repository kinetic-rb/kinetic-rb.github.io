#include <iostream>
#include <queue>

using namespace std;

char mp[1005][1005];
bool gone[1005][1005];
int ans[1005][1005], drct[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

struct p {
    int x, y;
    p() {
        x = y = 0;
    }
} p1, p2, pp;

int main() {
    int n, i, j;
    cin >> n;
    queue<p> q;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cin >> mp[i][j];
    }
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    pp.x = p1.x;
    pp.y = p1.y;
    q.push(pp);
    gone[pp.x][pp.y] = true;
    while (!q.empty()) {
        p p3 = q.front();
        q.pop();
        p tmp;
        for (i = 0; i < 4; i++) {
            tmp.x = p3.x + drct[i][0];
            tmp.y = p3.y + drct[i][1];
            if (tmp.x > 0 && tmp.x <= n && tmp.y > 0 && tmp.y <= n && !gone[tmp.x][tmp.y] &&
                mp[tmp.x][tmp.y] == '0') {
                ans[tmp.x][tmp.y] = max(ans[tmp.x][tmp.y], ans[p3.x][p3.y] + 1);
                gone[tmp.x][tmp.y] = true;
                if (tmp.x == p2.x && tmp.y == p2.y) {
                    printf("%d", ans[p2.x][p2.y]);
                    return 0;
                }
                q.push(tmp);
            }
        }
    }
    return 0;
}