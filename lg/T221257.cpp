#include <iostream>

using namespace std;

long long gcd(long long x, long long y) {
    return !y ? x : gcd(y, x % y);
}

long long lcd(long long x, long long y) {
    return x * y / gcd(x, y);
}

int main() {
    long long t, x, y;
    for (cin >> t; t--; cout << gcd(x, y) << " " << lcd(x, y) << '\n') {
        cin >> x >> y;
    }
    return 0;
}