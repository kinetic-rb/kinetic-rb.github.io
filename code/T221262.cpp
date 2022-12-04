#include <iostream>

using namespace std;

int ac[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ac[i] = (ac[i - 1] + x) % 1000000007;
    }
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        cout << (ac[r] - ac[l - 1] + 1000000007) % 1000000007 << '\n';
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