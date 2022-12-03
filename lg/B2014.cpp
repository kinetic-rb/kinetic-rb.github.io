#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double r;
    cin >> r;
    cout << fixed << setprecision(4) << 2 * r << " " << 2 * 3.14159 * r << " " << 3.14159 * r * r;
    return 0;
}