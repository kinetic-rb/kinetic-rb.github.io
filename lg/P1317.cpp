#include <iostream>

using namespace std;

signed main() {
    signed a, ans = 0, n;
    bool l = false;
    cin >> n >> a;
    for (signed i = 0; i < n; i++) {
        signed b;
        cin >> b;
        if (b < a) {
            l = true;
        }
        if (b > a && l) {
            ans++;
            l = false;
        }
        a = b;
    }
    cout << ans;
    return 0;
}