#include <iostream>

using namespace std;

int a[1005][1005], b[100005];
int n;

int main() {
    ios_base::sync_with_stdio(false);
\tcin >> n;
\tfor (int i = 1; i <= n; i++) {
\t\tint x1, y1, x2, y2;
\t\tcin >> x1 >> y1 >> x2 >> y2;
\t\ta[x1][y1]++;
\t\ta[x2 + 1][y1]--;
\t\ta[x1][y2 + 1]--;
\t\ta[x2 + 1][y2 + 1]++;
\t}
\tfor (int i = 1; i < 1002; i++)
\t\tfor (int j = 1, s = 0; j < 1002; j++) {
\t\t\ta[i][j] += a[i - 1][j];
\t\t\ts += a[i][j];
\t\t\tb[s]++;
\t\t}
\tfor (int i = 1; i <= n; i++)
\t\tcout << b[i] << ' ';
\treturn 0;
}