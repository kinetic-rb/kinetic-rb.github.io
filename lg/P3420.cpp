#include <iostream>

using namespace std;

long f[2000002];

long find(const long& u) {
    return (f[u] == u ? u : f[u] = find(f[u]));
}

signed main() {
    ios_base::sync_with_stdio(false);
    long n, cnt = 0;
    cin >> n;
    for (long i = 1; i < n; i++)
        f[i] = i;
    for (long i = 0; i < n; i++) {
        long x;
        cin >> x;
        f[find(i)] = f[find(x - 1)];
    }
    for (long i = 0; i < n; i++)
        if (i == f[i])
            cnt++;
    cout << cnt;
    return 0;
}