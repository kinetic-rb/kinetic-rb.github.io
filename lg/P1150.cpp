#include <iostream>

using namespace std;

int main() {
    int n, k, t, sum;
    cin >> n >> k;
    sum = n;
    while(n >= k) {
        t = n / k;
        n -= t * k;
        n += t;
        sum += t;
    }
    cout << sum;
    return 0;
}