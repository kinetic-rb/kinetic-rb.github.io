#include <iostream>
#include <functional>

using namespace std;

bool f[10010];

int main() {
    int n, ans = 0;
    cin >> n;
    function<void (int, int)> c = [&](int p, int m) {
        if (p) {
            for (int r = p; r; r--)
                c(p - r, r * (p - r) + m);
            return;
        }
        if(!f[m])
            ans++;
        f[m] = true;
    };
    c(n, 0);
    cout << ans;
    return 0;
}