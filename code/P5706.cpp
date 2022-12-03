#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    cout << fixed << setprecision(3) << x / y << "\n" << fixed << setprecision(0) << y * 2;
    return 0;
}