#include <iostream>

using namespace std;

short a[1001], b[1001];

int main() {
\tint n, v = 0;
\tcin >> n;
\tfor (int i = 0; i < n; i++)
\t\tcin >> a[i];
\tfor (int i = 0; i < n; i++)
\t\tcin >> b[i];
\tfor (int i = 0; i < n; i++)
\t\tv += a[i] * b[i];
\tcout << v;
\treturn 0;
}