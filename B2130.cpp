#include <iostream>

using namespace std;

int main() {
    int x, y;
    char op;
    cin >> x >> op >> y;
    switch(op) {
        case '+' : cout << x + y; exit(0);
        case '-' : cout << x - y; exit(0);
        case '*' : cout << x * y; exit(0);
        case '/' : cout << x / y; exit(0);
        default : cout << x % y;
    }
    return 0;
}