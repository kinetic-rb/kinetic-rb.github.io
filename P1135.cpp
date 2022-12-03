#include <iostream>
#include <cstring>
#include <functional>

using namespace std;

int d[205];

int main() {
    memset(d, -1, sizeof d);
    int n, a, b, *go;
    cin >> n >> a >> b;
    go = (int *) malloc(n << 3);
    for (int i = 1; i <= n; i++) {
        cin >> go[i];
    }
    function<void (int, int)> dfs = [&](int x, int step) {
        if (x < 1 || x > n || step > n || (d[x] != -1 && step >= d[x]))
            return;
        d[x] = step;
        dfs(x + go[x], step + 1);
        dfs(x - go[x], step + 1);
    };
    dfs(a, 0);
    cout << d[b];
    return 0;
}