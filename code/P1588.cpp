#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

int main() {
    int n, ans;
    cin >> n;
    function<void (int, int, int)> dfs = [&](int x, int y, int step) -> void {
        if (ans <= step)
            return;
        ans = min(ans, step + abs(y - x));
        if (x == y) {
            ans = min(ans, step);
            return;
        }
        if (x > y) {
            ans = min(ans, step + x - y);
            return;
        } else {
            if(y & 1) {
                dfs(x, y + 1, step + 1);
                dfs(x, y - 1, step + 1);
            } else dfs(x, y >> 1, step + 1);
        }
    };
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (y < x) {
            cout << x - y << '\n';
            continue;
        }
        ans = y - x;
        dfs(x, y, 0);
        cout << ans << '\n';
    }
    return 0;
}