#include <iostream>

using namespace std;

int main() {
    ios :: sync_with_stdio(0);
    int m;
    cin >> m;
    m *= 2;
    for(int L = 0; L * 2 < m; L++) {
        for(int R = L; (R + L) * (R - L + 1) <= m; R++) {
            if((R + L) * (R - L + 1) == m) {
                cout << L << " " << R << endl;
            }
        }
    }
    return 0;
}