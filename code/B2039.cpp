#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if(x == y) {
        cout << '=';
        return 0;
    }
    x > y ? cout << '>' : cout << '<';
    return 0;
}