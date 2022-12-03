#include <iostream>

using namespace std;

int num[305], sum[305], f[3][305][305];

int main() {
\tint n, mx = -1, mi = 0x7fffffff, m;
\tcin >> n;
\tm = n << 1;
\tfor(int i = 1; i <= m; i++) {
\t\tif(i <= n)
\t\t\tcin >> num[i];
\t\tnum[i + n] = num[i];
\t\tsum[i] = sum[i - 1] + num[i];
\t}
\tfor(int p = 1; p < n; p++)
\t\tfor(int i = 1, j = 1 + p; (i < m) && (j < m); i++, j = i + p) {
\t\t\tf[2][i][j] = 0x7fffffff;
\t\t\tfor(int k = i; k < j; k++) {
\t\t\t\tf[1][i][j] = max(f[1][i][j], f[1][i][k] + f[1][k + 1][j] + sum[j] - sum[i - 1]);
\t\t\t\tf[2][i][j] = min(f[2][i][j], f[2][i][k] + f[2][k + 1][j] + sum[j] - sum[i - 1]);
\t\t\t}
\t\t}
\tfor(int i = 1; i <= n; i++) {
\t\tmx = max(mx, f[1][i][i + n - 1]);
\t\tmi = min(mi, f[2][i][i + n - 1]);
\t}
\tcout << mi << '\n' << mx;
\treturn 0;
}