#include <iostream>

using namespace std;

short b[1001][1001];

int main() {
\tint n, t;
\tios_base::sync_with_stdio(false);
\tfor (cin >> n >> t; t--;) {
\t\tint sx, sy, ex, ey;
\t\tcin >> sx >> sy >> ex >> ey;
\t\tfor (int i = sx; i <= ex; i++)
\t\t\tfor (int j = sy; j <= ey; j++)
\t\t\t\tb[i][j]++;
\t}
\tfor (int i = 1; i <= n; i++) {
\t\tfor (int j = 1; j <= n; j++)
\t\t\tcout << b[i][j] << ' ';
\t\tcout << '\n';
\t}
\treturn 0;
}