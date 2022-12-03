#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, x = 1, y = 1, z;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        z = x + y;
        x = y;
        y = z;
        sum += y * 1.0 / x;
    }
    cout << fixed << setprecision(4) << sum;
    return 0;
}