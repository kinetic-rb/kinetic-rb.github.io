#include <iostream>

using namespace std;

int f[1001][1001];

int main() {
\tint n;
\tcin >> n;
\tf[1][1] = 1;
\tfor (int i = 2; i <= n << 1; i++)
\t\tfor (int j = (i + 1) >> 1; j <= i; j++)
\t\t\tf[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % 100;
\tcout << f[n * 2][n];
\treturn 0;
}