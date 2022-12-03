#include <iostream>
#include <iomanip>
#define maximum(a, b, c) max(a, max(b, c))

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(3) << maximum(a, b, c) / maximum(a + b, b, c) / maximum(a, b, b + c);
    return 0;
}