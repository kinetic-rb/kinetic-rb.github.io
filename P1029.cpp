#include <iostream>

using namespace std;

inline long long gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

inline long long lcm(int x, int y) {
    return x * y / gcd(x, y);
}

inline bool check(int x, int y, int p, int q) {
    return gcd(p, q) == x && lcm(p, q) == y;
}

int main() {
    int x, y, p = 1, q = 1, cnt = 0;
    cin >> x >> y;
    for (p = x; p <= y; p++) {
        q = x * y / p;
        if (check(x, y, p, q)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}