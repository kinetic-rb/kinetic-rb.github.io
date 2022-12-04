#include <iostream>

using namespace std;

int a[101];

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 10 - (a[i] % 100 - a[i] % 10) / 10 - (a[i] % 1000 - a[i] % 10 - 10 * (a[i] % 100 - a[i] % 10) / 10) / 100 - a[i] / 1000 > 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}