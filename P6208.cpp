#include <iostream>

using namespace std;

int f[1001][1001], num[1001][1001];

int main() {
\tint n, m;
\tcin >> n >> m;
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = 1; j <= m; j++)
\t\t\tcin >> num[i][j];
\tf[1][1] = num[1][1];
\tfor (int i = 1; i <= m; i++)
\t\tfor (int j = 1; j <= n && j <= i; j++)
\t\t\tf[j][i] = max(f[j - 1][i - 1], max(f[j + 1][i - 1], f[j][i - 1])) + num[j][i];
\tcout << f[n][m];
\treturn 0;
}