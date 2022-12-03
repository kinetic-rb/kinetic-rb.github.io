#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int d[1000001];

int main() {
    int sx, ex;
    queue<int> Q;
    function<void (int, int)> record = [&](int x, int step) -> void {
        if (x < 0 || x > ex * 2 || step >= d[x])
            return;
        Q.push(x);
        d[x] = step;
    };
    function<void (int)> bfs = [&](int x) -> void {
        for (record(x, 0); !Q.empty(); ) {
            int u = Q.front();
            Q.pop();
            record(u + 1, d[u] + 1);
            record(u - 1, d[u] + 1);
            record(u * 2, d[u] + 1);
        }
    };
    int t;
    for (cin >> t; t--; ) {
        for (auto &i : d) {
            i = 0x7fffffff;
        }
        cin >> sx >> ex;
        if (sx >= ex) {
            cout << sx - ex << '\n';
            continue;
        }
        bfs(sx);
        cout << d[ex] << '\n';
    }
    return 0;
}