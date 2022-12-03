#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int stamp[55], d[2000000];

int main() {
    int k, n, MAX = 0;
    cin >> k >> n;
    for (int & i : d)
        i = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        cin >> stamp[i];
        MAX = max(MAX, stamp[i]);
    }
    queue<int> Q;
    function<void (int, int)> record = [&](int money, int step) -> void {
        if (money > MAX * k || step > k || step > d[money] || d[money] != 0x7fffffff)
            return;
        Q.push(money);
        d[money] = step;
    };
    function<void (int)> bfs = [&](int sx) -> void {
        for (record(sx, 0); !Q.empty();) {
            auto u = Q.front();
            Q.pop();
            for (int i = 0; i < n; i++) {
                record(u + stamp[i], d[u] + 1);
            }
        }
    };
    bfs(0);
    for (int i = 0; i < 2000000; i++)
        if (d[i] == 0x7fffffff) {
            cout << --i;
            return 0;
        }
    return 0;
}