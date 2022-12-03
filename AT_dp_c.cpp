#include <iostream>

using namespace std;

int a[100005], b[100005], c[100005], f[100005][4];

int main() {
\tint n;
\tcin >> n;
\tfor (int i = 1; i <= n; i++)
\t\tcin >> a[i] >> b[i] >> c[i];
\tfor (int i = 1; i <= n; i++) {
\t\tf[i][1] = max(f[i - 1][2],f[i - 1][3]) + a[i];
\t\tf[i][2] = max(f[i - 1][1],f[i - 1][3]) + b[i];
\t\tf[i][3] = max(f[i - 1][1],f[i - 1][2]) + c[i];
\t}
\tcout << max(f[n][1], max(f[n][2], f[n][3]));
\treturn 0;
}