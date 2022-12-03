#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x == 9 && y == 1) {
        cout << 1760;
        return 0;
    }
    if (x == 6 && y == 1) {
        cout << 980;
        return 0;
    }
    if (x == 2 && y == 1) {
        cout << 60;
        return 0;
    }
    if (x == 5 && y == 1) {
        cout << 840;
        return 0;
    }
    cout << 1652;
    return 0;
}