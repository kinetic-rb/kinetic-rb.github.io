#include <iostream>

using namespace std;

int main() {
    int n;
    for (cin >> n; n != 1; ) {
        if (n & 1) {
            cout << n << "*3+1=" << n * 3 + 1 << '\n';
            n = n * 3 + 1;
        } else {
            cout << n << "/2=" << n / 2 << '\n';
            n /= 2;
        }
    }
    cout << "End";
    return 0;
}