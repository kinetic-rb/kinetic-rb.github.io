#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n, x, y;
    cin >> n >> x >> y;
    cout << max(double(0), floor(n - y / x));
    return 0;
}