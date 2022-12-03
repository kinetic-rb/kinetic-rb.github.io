#include<iostream>

using namespace std;

int num[351], cnt[5], f[41][41][41][41];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= m; i++) {
        int c;
        cin >> c;
        cnt[c]++;
\t\t}
    ****f = num[1];
    for (int i = 0; i <= cnt[1]; i++)
        for (int j = 0; j <= cnt[2]; j++)
            for (int k = 0; k <= cnt[3]; k++)
                for (int p = 0; p <= cnt[4]; p++) {
                    int l = 1 + i * 1 + j * 2 + k * 3 + p * 4;
                    if (i - 1 > -1)
                        f[i][j][k][p] = max(f[i - 1][j][k][p] + num[l], f[i][j][k][p]);
                    if (j - 1 > -1)
                        f[i][j][k][p] = max(f[i][j - 1][k][p] + num[l], f[i][j][k][p]);
                    if (k - 1 > -1)
                        f[i][j][k][p] = max(f[i][j][k - 1][p] + num[l], f[i][j][k][p]);
                    if (p - 1 > -1)
                        f[i][j][k][p] = max(f[i][j][k][p - 1] + num[l], f[i][j][k][p]);
\t\t\t\t}
    cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
    return 0;
}