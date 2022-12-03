#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 2;; x++) {
        if (a % x == b % x && c % x == b % x) {
            cout << x;
            return 0;
        }
    }
}