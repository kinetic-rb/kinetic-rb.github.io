#include <iostream>

using namespace std;

int main() {
    int n, m, p, ans = 1;
    cin >> n >> n >> m >> p;
    n -= m - 1;
    for (int i = n - m + 1; i <= n; i++) {
        ans = 1ll * ans * i % p;
    }
    cout << ans;
    return 0;
}