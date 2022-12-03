#include <iostream>

int main() {
    double x, sum = 0, s = 2;
    int cnt = 0;
    for(std :: cin >> x; sum < x; sum += s, s *= 0.98)
        cnt++;
    std :: cout << cnt;
    return 0;
}