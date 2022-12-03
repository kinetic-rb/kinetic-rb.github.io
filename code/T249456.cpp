#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && c + b > a) {
        if (a == b && b == c) {
            cout << "equilateral triangle";
        } else if (a == b || b == c || a == c) {
            cout << "isosceles triangle";
        } else {
            cout << "normal triangle";
        }
    } else {
        cout << "not triangle";
    }
    return 0;
}