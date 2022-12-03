#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double f;
    cin >> f;
    cout << fixed << setprecision(5) << 5 * (f - 32) / 9;
    return 0;
}