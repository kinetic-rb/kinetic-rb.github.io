#include <iostream>
#include <functional>

using namespace std;

bool vis[101][101][101];

int main() {
    int a, b, c, m, MIN = 0x7fffffff;
    cin >> a >> b >> c >> m;
    function<void (int, int, int)> dfs = [&](int x, int y, int step) {
        if (step > c || vis[x][y][step]) {
            return;
        }
        vis[x][y][step] = true;
        MIN = min(MIN, abs(x + y - m));
        dfs(a, y, step + 1);
        dfs(x, b, step + 1);
        dfs(0, y, step + 1);
        dfs(x, 0, step + 1);
        dfs(x - min(b - y, x), y + min(b - y, x), step + 1);
        dfs(x + min(a - x, y), y - min(a - x, y), step + 1);
    };
    dfs(0, 0, 0);
    cout << MIN;
    return 0;
}