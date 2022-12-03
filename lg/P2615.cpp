#include <iostream>

using namespace std;

int mp[40][40];

int main() {
\tint n;
\tcin >> n;
\tfor (int step = 1; step <= n * n; step++) {
\t\tstatic int llx, lly;
\t\tif (step == 1)
\t\t\tmp[llx = 1][lly = n / 2 + 1] = step;
\t\telse if (llx == 1 && lly != n)
\t\t\tmp[llx = n][++lly] = step;
\t\telse if (llx != 1 && lly == n)
\t\t\tmp[--llx][lly = 1] = step;
\t\telse if (llx == 1 && lly == n)
\t\t\tmp[++llx][lly] = step;
\t\telse if (llx != 1 && lly != n)
\t\t\tmp[llx - 1][lly + 1] ? mp[++llx][lly] = step : mp[--llx][++lly] = step;
\t}
\tfor (int i = 1; i <= n; ++i) {
\t\tfor (int j = 1; j <= n; ++j)
\t\t\tcout << mp[i][j] << ' ';
\t\tcout << '\n';
\t}
\treturn 0;
}