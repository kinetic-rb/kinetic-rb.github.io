#include <iostream>

using namespace std;

int ac[100001];
int n, t, Find;

inline int brs() {
    int l, r, m;
    for(l = 1, r = n; l <= r; ) {
        m = (l + r) * 0.5;
        if(ac[m] < Find) {
        }
        (ac[m] < Find) ? l = m + 1 : r = m - 1;
    }
    return r + 1;
}

int main() {
    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> ac[i];
    }
    for(int i = 1; i <= t; i++) {
        cin >> Find;
        int ans = brs();
        cout << ans << '\n';
    }
    return 0;
}