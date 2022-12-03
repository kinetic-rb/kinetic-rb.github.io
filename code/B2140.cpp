#include <iostream>

using namespace std;

inline bool P(int x) {
    int z = 0, o = 0;
    for (; x; x >>= 1) {
        x & 1 ? o++ : z++;
    }
    return o > z;
}

int main() {
    int n, A = 0, B = 0;
    for (cin >> n; n; P(n--) ? A++ : B++);
    cout << A << ' ' << B;
    return 0;
}