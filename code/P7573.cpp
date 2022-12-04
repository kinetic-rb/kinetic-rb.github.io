#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int p;
        cin >> p;
        (p == 1) ? cout << "0
" : cout << ((p + 1) >> 1) << '\n';
    }
    return 0;
}