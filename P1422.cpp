#include <iostream>
#include <iomanip>

int main() {
    int e;
    double sum = 0;
    std :: cin >> e;
    sum += std :: min(e, 150) * 0.4463;
    e -= std :: min(e, 150);
    sum += std :: min(e, 250) * 0.4663;
    e -= std :: min(e, 250);
    sum += std :: max(e, 0) * 0.5663;
    std :: cout << std :: fixed << std :: setprecision(1) << sum;
    return 0;
}