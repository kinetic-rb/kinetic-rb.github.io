#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a / 100 << b / 10 % 10 << b % 10 << " " << b / 100 << a / 10 % 10 << a % 10;
    return 0;
}