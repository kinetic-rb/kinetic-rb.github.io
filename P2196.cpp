#include <iostream>
#include <algorithm>

using namespace std;

bool l[205][205];
int f[205], num[205];
int way[205];

inline void so(int u) {
\tif (!way[u]) {
\t\tcout << u;
\t\treturn;
\t}
\tso(way[u]);
\tcout << ' ' << u;
}

int main() {
\tint n, MAX = 0;
\tcin >> n;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> num[i];
\t\tf[i] = num[i];
\t}
\tfor (int i = 1; i < n; i++)
\t\tfor (int j = i + 1; j <= n; j++) {
\t\t\tbool h;
\t\t\tcin >> h;
\t\t\tif (h)
\t\t\t\tl[i][j] = true;
\t\t}
\tfor (int s = 1; s <= n; s++)
\t\tfor (int i = 1; i <= n; i++)
\t\t\tif (l[i][s])
\t\t\t\tif (f[i] + num[s] > f[s]) {
\t\t\t\t\tf[s] = f[i] + num[s];
\t\t\t\t\tway[s] = i;
\t\t\t\t}
\tMAX = max_element(f + 1, f + n + 1) - f;
\tso(MAX);
\tcout << '\n' << f[MAX];
\treturn 0;
}