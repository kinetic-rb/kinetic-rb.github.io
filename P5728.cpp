#include <iostream>

using namespace std;

int a[1010][5], sum[1010];

int main() {
\tint cnt = 0, n;
\tcin >> n;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> a[i][1] >> a[i][2] >> a[i][3];
\t\tsum[i] = a[i][1] + a[i][2] + a[i][3];
\t}
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = i + 1; j <= n; j++)
\t\t\tif (abs(a[i][1] - a[j][1]) < 6 && abs(a[i][2] - a[j][2]) < 6 && abs(a[i][3] - a[j][3]) < 6 && abs(sum[i] - sum[j]) < 11)
\t\t\t\tcnt++;
\tcout << cnt;
\treturn 0;
}