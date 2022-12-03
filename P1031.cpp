#include <iostream>

using namespace std;

int n, a[110], c[110], p, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        c[i] = c[i - 1] + a[i];
    p = c[n] / n;
    for (int i = 1; i < n; i++)
        if (p * i != c[i])
            ans++;
    cout << ans;
    return 0;
}