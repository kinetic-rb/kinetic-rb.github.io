#include <iostream>

using namespace std;

int num[20][20], f[20][20], de[20][20], ans[20];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> num[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= j; k++)
                if (num[i][k] + f[i - 1][j - k] >= f[i][j]) {
                    f[i][j] = num[i][k] + f[i - 1][j - k];
                    de[i][j] = k;
                }
    cout << f[n][m] << '\n';
    for (int i = n; i > 0; i--) {
        ans[i] = de[i][m];
        m -= de[i][m];
    }
    for (int i = 1; i <= n; i++)
        cout << i << ' ' << ans[i] << '\n';
    return 0;
}