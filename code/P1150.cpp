#include <iostream>

using namespace std;

int main() {
    int n, k, t, sum;
    cin >> n >> k;
    sum = n;
    for (sum = n; n >= k; sum += t) {
        t = n / k;
        n -= t * k;
        n += t;
    }
    cout << sum;
    return 0;
}