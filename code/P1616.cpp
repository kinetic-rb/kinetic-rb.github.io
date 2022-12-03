#include <iostream>

using namespace std;

int t[10001], c[10001];
long f[10000100];

signed main() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> c[i];
    for (int i = 0; i < n; i++)
        for (int v = t[i]; v <= m; v++)
            f[v] = max(f[v], f[v - t[i]] + c[i]);
    cout << f[m];
    return 0;
}