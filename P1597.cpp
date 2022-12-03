#include <iostream>

using namespace std;

char d[300];
int a[10] = { 0 };

int main() {
\tcin >> d;
\tfor (int i = 0; d[i]; i++)
\t\tif (d[i + 1] == ':' && d[i + 2] == '=') {
\t\t\tif (d[i + 3] >= '0' && d[i + 3] <= '9')
\t\t\t\ta[d[i] - 'a'] = d[i + 3] - '0';
\t\t\tif (d[i + 3] >= 'a' && d[i + 3] <= 'z')
\t\t\t\ta[d[i] - 'a'] = a[d[i + 3] - 'a'];
\t\t}
\tcout << a[0] << ' ' << a[1] << ' ' << a[2];
\treturn 0;
}