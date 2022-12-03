#include <iostream>

using namespace std;

int ps[101][101];

int main() {
\tint n, m, MAX = 0;
\tcin >> n >> m;
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = 1; j <= m; j++) {
\t\t\tcin >> ps[i][j];
\t\t}
\tfor (int x = 1; x <= n; x++) {
\t\tfor (int y = 1; y <= m; y++) {
\t\t\tfor (int xx = x; xx <= n; xx++) {
\t\t\t\tfor (int yy = y; yy <= m; yy++) {
\t\t\t\t\tif (yy - y == xx - x) {
\t\t\t\t\t\tbool al = true;
\t\t\t\t\t\tfor (int i = x; i <= xx && al; i++)
\t\t\t\t\t\t\tfor (int j = y; j <= yy; j++)
\t\t\t\t\t\t\t\tif (!ps[i][j]) {
\t\t\t\t\t\t\t\t\tal = false;
\t\t\t\t\t\t\t\t\tbreak;
\t\t\t\t\t\t\t\t}
\t\t\t\t\t\tif (al) {
\t\t\t\t\t\t\tMAX = max(MAX, yy - y + 1);
\t\t\t\t\t\t}
\t\t\t\t\t}
\t\t\t\t}
\t\t\t}
\t\t}
\t}
\tcout << MAX;
\treturn 0;
}