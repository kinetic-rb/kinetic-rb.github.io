#include <iostream>

using namespace std;

int main() {
    int x, y;
    char op;
    cin >> x >> y >> op;
    if (op == '/' && !y) {
        cout << "Divided by zero!";
        return 0;
    }
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        cout << "Invalid operator!";
        return 0;
    }
    if (op == '+')
        cout << x + y;
    if (op == '-')
        cout << x - y;
    if (op == '*')
        cout << x * y;
    if (op == '/')
        cout << x / y;
    return 0;
}