#include <iostream>
#include <cmath>

using namespace std;

double f_x_n(double x, double n) {
    return (n == 1) ? sqrt(1 + x) : sqrt(n + f_x_n(x, n - 1));
}

int main() {
    double n, x;
    cin >> x >> n;
    printf("%.2lf", f_x_n(x, n));
    return 0;
}