#include <cstring>
#include <iostream>
#define Sum(s, e) sum[e] - sum[s - 1]

using namespace std;

int f[301][301], num[301], sum[301];

signed main() {
\tmemset(f, 127, sizeof f);
\tint n;
\tcin >> n;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> num[i];
\t\tsum[i] = sum[i - 1] + num[i];
\t\tf[1][i] = 0;
\t}
\tfor (int i = 2; i <= n; i++)
\t\tfor (int j = 1; j <= n - i + 1; j++) {
\t\t\tfor (int k = 1; k < i; k++)
\t\t\t\tf[i][j] = min(f[i][j], f[k][j] + f[i - k][j + k] + Sum(j, j + i - 1));
\t\t}
\tcout << f[n][1];
\treturn 0;
}