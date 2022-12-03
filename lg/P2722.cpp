#include <iostream>

using namespace std;

int w[10001], c[10001], f[10001];

int main() {
    ios_base::sync_with_stdio(false);
\tint  n, v;
\tcin >> v >> n;
\tfor (int i = 0; i < n; i++)
\t\tcin >> w[i] >> c[i];
\tfor (int i = 1; i <= v; i++)
\t\tfor (int j = 0; j < n; j++)
\t\t\tfor (int k = 0; k * c[j] <= i; k++)
\t\t\t\tf[i] = max(f[i], k * w[j] + f[i - k * c[j]]);
\tcout << f[v];
\treturn 0;
}