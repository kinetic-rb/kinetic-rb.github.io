#include <iostream>
#define int long

using namespace std;

signed main() {
    int T;
    for (cin >> T; T--;) {
        int sum = 0, n;
        cin >> n;
        for (int pew = 1; n; n /= 10, pew *= 9)
            sum += pew * (n % 10) - (n % 10 > 6 ? pew : 0);
        cout << sum << '\n';
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