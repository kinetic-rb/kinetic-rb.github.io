#include <iostream>
#include <vector>

using namespace std;

vector<int> B, E;

int main() {
\tint n, m, nowb = 0, nowe = 0, cnt = 0;
\tchar w = '#';
\tcin >> n >> m;
\tfor (int i = 0; i < n; i++) {
\t\tint x, y;
\t\tcin >> x >> y;
\t\tfor (int j = 0; j < y; j++)
\t\t\tB.push_back(x);
\t}
\tfor (int i = 0; i < m; i++) {
\t\tint x, y;
\t\tcin >> x >> y;
\t\tfor (int j = 0; j < y; j++)
\t\t\tE.push_back(x);
\t}
\tfor (int p = 0; p < B.size(); p++) {
\t\tnowb += B[p];
\t\tnowe += E[p];
\t\tif (w == '#') {
\t\t\tif (nowb == nowe)
\t\t\t\tw = '#';
\t\t\tif (nowb > nowe)
\t\t\t\tw = 'B';
\t\t\tif (nowe > nowb)
\t\t\t\tw = 'E';
\t\t\tcontinue;
\t\t}
\t\tif (w == 'B') {
\t\t\tif (nowe > nowb) {
\t\t\t\tcnt++;
\t\t\t\tw = 'E';
\t\t\t}
\t\t\tcontinue;
\t\t}
\t\tif (w == 'E') {
\t\t\tif (nowb > nowe) {
\t\t\t\tcnt++;
\t\t\t\tw = 'B';
\t\t\t}
\t\t}
\t}
\tcout << cnt;
\treturn 0;
}