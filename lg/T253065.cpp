#include <iostream>

using namespace std;

int main() {
    char x[4];
    cin >> x[0] >> x[1] >> x[2];
    int a, b;
    a = (x[2] - '0') * 100 + (x[1] - '0') * 10 + x[0] - '0';
    b = (x[0] - '0') * 100 + (x[1] - '0') * 10 + x[2] - '0';
    cout << a + b;
    return 0;
}