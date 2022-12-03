#include <iostream>

using namespace std;

int main() {
    double v = 7, s, x, l = 0;
    for(cin >> s >> x; l < s - x; v *= 0.98)
        l += v;
    (v * 0.98 <= s + x - l) ? cout << 'y' : cout << 'n';
    exit(0);
}