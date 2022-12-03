#include <iostream>

using namespace std;

long f[1001];
bool b[1001];

int main() {
\tint n;
\tfor (int i = 2; i < 500; i++)
\t\tif (!b[i])
\t\t\tfor (int j = 2; i * j <= 1001; j++)
\t\t\t\tb[i * j] = 1;
\tcin >> n;
\t*f = 1;
\tfor (int i = 2; i <= n; i++)
\t\tif (!b[i])
\t\t\tfor (int j = i; j <= n; j++)
\t\t\t\tf[j] += f[j - i];
\tcout << f[n];
  \treturn 0;
}