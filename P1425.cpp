#include <iostream>
int main() {
    int a, b, c, d;
    std :: cin >> a >> b >> c >> d;
    b += a * 60;
    d += c * 60;
    std :: cout << (d - b) / 60 << " " << (d - b) % 60;
    return 0;
}