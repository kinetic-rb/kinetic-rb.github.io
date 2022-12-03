#include <iostream>
#include <cmath>

using namespace std;

int digit(int n, int k) {
    int v[k];
    for (int i = 0; i < k; i++)
        v[i] = n / pow(10, i);
    return v[k - 1] % 10;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << digit(n, k);
    return 0;
}