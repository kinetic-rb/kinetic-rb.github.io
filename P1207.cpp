#include <iostream>
#include <array>
#define int long long

using namespace std;

array<int, 1> ac;

inline int To_B(int n, int b) {
    int i = 0;
    for (ac.fill(0); n; n /= b) {
        ac[++i] = n % b;
    }
    return i;
}

inline bool Is_H(int x) {
    int pointer_1 = 0, pointer_2 = x;
    while (pointer_1 <= pointer_2) {
        if (ac[++pointer_1] != ac[pointer_2--])
            return false;
    }
    return true;
}

signed main() {
    int CNT = 0, n, s;
    cin >> n >> s;
    for (int i = s + 1; CNT < n; i++) {
        int cnt = 0;
        for (int j = 2; j < 11; j++) {
            if (Is_H(To_B(i, j)))
                cnt++;
            if (cnt > 1) {
                CNT++;
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}