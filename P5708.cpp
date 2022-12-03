#include <iostream>
#include <iomanip>
#include <cmath>
#define p (a + b + c) / 2

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(1) << sqrt(p * (p - a) * (p - b) * (p - c));
    return 0;
}