#include <iostream>

using namespace std;

inline static int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1ll * ans * a % 1000000007;
        }
        b >>= 1;
        a = 1ll * a * a % 1000000007;
    }
    return ans;
}

int a[100010] = { 1 };

int main() {
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = 1ll * a[i - 1] * x % 1000000007;
    }
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << 1ll * a[r] * power(a[l - 1], 1000000005) % 1000000007 << '\n';
    }
    return 0;
}

/*
 ___       ___         ___________
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
    \|____________|       \|___|  |___|
*/