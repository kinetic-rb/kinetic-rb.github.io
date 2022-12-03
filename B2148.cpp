#include <iostream>

using namespace std;

double fxn(double x, double n) {
    return (n == 1) ? x / (1 + x) : x / (n + fxn(x, n - 1));
}

int main() {
    double n, x;
    cin >> x >> n;
    printf("%.2lf
", fxn(x, n));
    return 0;
}