#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c > max(a, max(b, c)) * 2);
    return 0;
}