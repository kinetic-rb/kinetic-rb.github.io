#include <iostream>

int main() {
    int x, n, sum = 0;
    for(std :: cin >> x >> n; n--; x++) {
        if(x % 7 != 6 && x % 7 != 0) {
            sum += 250;
            //std :: cout << x % 7 << '\n';
        }
    }
    std :: cout << sum;
    return 0;
}