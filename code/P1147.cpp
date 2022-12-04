#include <iostream>

using namespace std;

int main() {
    int m;
    cin >> m;
    m <<= 1;
    for (int L = 0; L * 2 < m; L++) {
        for (int R = L; (R + L) * (R - L + 1) <= m; R++) {
            if ((R + L) * (R - L + 1) == m) {
                cout << L << " " << R << '\n';
            }
        }
    }
    return 0;
}