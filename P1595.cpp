#include <iostream>

using namespace std;

long long f[21] = {0, 0, 1};

int main() {
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] * i;
        (i & 1) ? f[i]-- : f[i]++;
    }
    cout << f[n];
    return 0;
}