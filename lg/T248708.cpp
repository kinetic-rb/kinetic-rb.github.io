#include <iostream>

using namespace std;

int main() {
    char x, y;
    int a, b, c;
    cin >> a >> x >> b >> y >> c;
    (x == '-') ? b = a - b : b += a;
    (y == '-') ? c = b - c : c += b;
    cout << c;
    return 0;
}