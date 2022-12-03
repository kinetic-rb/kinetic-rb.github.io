#include <iostream>

using namespace std;

int f[1001][1001];
int n, m;

int main() {
\tcin >> n >> m;
\tf[0][1] = 1;
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = 1; j <= m; j++)
\t\t\tf[i][j] = (f[i - 1][j] + f[i][j - 1]) % 1000000007;
\tcout << f[n][m];
\treturn 0;
}