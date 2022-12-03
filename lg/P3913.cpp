#include <iostream>
#include <algorithm>

using namespace std;

long long x[1000001], y[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> x[i] >> y[i];
    stable_sort(x, x + k);
    stable_sort(y, y + k);
    cout << n * n - (n - (unique(x, x + k) - x)) * (n - (unique(y, y + k) - y));
    return 0;
}