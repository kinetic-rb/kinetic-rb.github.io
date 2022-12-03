#include <iostream>

using namespace std;

int main() {
    char x[3], y[3];
    cin >> x[0] >> x[1] >> x[2] >> y[0] >> y[1] >> y[2];
    cout << x[0] << y[1] << x[2] << " " << y[0] << x[1] << y[2];
    return 0;
}