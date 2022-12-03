#include <iostream>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    a * a > b * c ? cout << "Alice" : cout << "Bob";
    return 0;
}