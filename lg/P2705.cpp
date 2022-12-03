#include <iostream>

int main() {
    int r, b, c, d, e;
    std :: cin >> r >> b >> c >> d >> e;
    std :: cout << std :: max(std :: min(b, r) * e * 2 + (r - std :: min(b, r)) * c + (b - std :: min(b, r)) * d, r * c + b * d);
    return 0;
}