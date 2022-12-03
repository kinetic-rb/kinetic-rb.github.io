#include <iostream>

using namespace std;

unsigned long long ans[51][51][51];

int main() {
    unsigned long long n, a, b;
    cin >> n >> a >> b;
    for (unsigned long long i = 0; i <= a; i++) {
        for (unsigned long long j = 0; j <= b; j++)
            ans[0][i][j] = 1;
    }
    for (unsigned long long i = 1; i <= n; i++) {
        for (unsigned long long j = 0; j <= a; j++)
            for (unsigned long long k = 0; k <= b; k++) {
                for (unsigned long long x = 0; x <= j; x++)
                    for (unsigned long long y = 0; y <= k; y++) {
                        ans[i][j][k] += ans[i - 1][j - x][k - y];
                    }
            }
    }
    cout << ans[n][a][b];
    return 0;
}