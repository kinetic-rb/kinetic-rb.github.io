#include <iostream>

using namespace std;

int gloc(int n, int x, int y) {
    if (x == 1)
        return y;
    if (y == n)
        return n + x - 1;
    if (x == n)
        return 3 * n - 2 - y + 1;
    if (y == 1)
        return (n - 1 << 2) - x + 2;
    return gloc(n - 2, x - 1, y - 1) + ((n - 1) << 2);
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << gloc(n, x, y);
    return 0;
}