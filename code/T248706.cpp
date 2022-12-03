#include <iostream>

using namespace std;

int main() {
    string x, y;
    cin >> x >> y;
    swap(x[0], y[0]);
    cout << x << " " << y;
    return 0;
}