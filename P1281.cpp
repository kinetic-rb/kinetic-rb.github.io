#include <cstring>
#include <iostream>
#define Sum(s, e) ps[e] - ps[s - 1]

using namespace std;

int ps[505], num[505], f[505][505];
pair <int, int> re[505];

int main() {
\tmemset(f, 127, sizeof f);
\tint m, k;
\tcin >> m >> k;
\tfor (int i = 1; i <= m; i++) {
\t\tcin >> num[i];
\t\tps[i] = ps[i - 1] + num[i];
\t\tf[i][0] = 0;
\t}
\t**f = 0;
\tfor (int i = 1; i <= k; i++)
\t\tfor (int j = i; j <= m; j++)
\t\t\tfor (int x = i; x <= j; x++)
\t\t\t\tif (max(f[i - 1][x - 1], Sum(x, j)) < f[i][j])
\t\t\t\t\tf[i][j] = max(f[i - 1][x - 1], Sum(x, j));
\tfor (int i = m, e = m, sum = 0, t = k; i > -1; i--) {
\t\tsum += num[i];
\t\tif (sum > f[k][m] || !i) {
\t\t\tre[--t] = make_pair(i + 1, e);
\t\t\te = i;
\t\t\tsum = num[i];
\t\t}
\t}
\tfor (int i = 0; i < k; i++)
\t\tcout << re[i].first << ' ' << re[i].second << '\n';
\treturn 0;
}