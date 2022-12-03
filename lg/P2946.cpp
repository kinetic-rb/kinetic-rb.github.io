#include <iostream>

using namespace std;

long long cow[2005], f[2005][2005];

int main() {
    int n, F;
    cin >> n >> F;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i];
        cow[i] %= F;
    }
    for (int i = 1; i <= n; i++)
        f[i][cow[i]] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < F; j++)
            f[i][j] = ((f[i][j] + f[i - 1][j]) % 100000000 + f[i - 1][(j - cow[i] + F) % F]) % 100000000;
    cout << *f[n];
    return 0;
}