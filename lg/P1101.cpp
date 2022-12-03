#include <iostream>

using namespace std;

char b[101][101], ans[101][101];
int dr[][2] = { 1, 0, 0, 1, 1, 1, -1, 0, 0, -1, -1, -1, 1, -1, -1, 1 };
int n;

inline string fs(int x, int y, int px, int py) {
\tstring s = "";
\tfor (int cnt = 0; min(x, y) > -1 and max(x, y) < n and cnt < 7; cnt++, x += px, y += py)
\t\ts.push_back(b[x][y]);
\treturn s;
}

inline void tc(int x, int y, int px, int py) {
\tfor (int cnt = 0; min(x, y) > -1 and max(x, y) < n and cnt < 7; cnt++, x += px, y += py)
\t\tans[x][y] = b[x][y];
}

int main() {
\tcin >> n;
\tfor (int i = 0; i < n; i++)
\t\tfor (int j = 0; j < n; j++) {
\t\t\tcin >> b[i][j];
\t\t\tans[i][j] = '*';
\t\t}
\tfor (int i = 0; i < n; i++)
\t\tfor (int j = 0; j < n; j++)
\t\t\tif (b[i][j] == 'y' || b[i][j] == 'g') {
\t\t\t\tfor (auto d : dr) {
\t\t\t\t\tif (fs(i, j, d[0], d[1]) == "yizhong" || fs(i, j, d[0], d[1]) == "gnohziy") {
\t\t\t\t\t\ttc(i, j, d[0], d[1]);
\t\t\t\t\t}
\t\t\t\t}
\t\t\t}
\tfor (int i = 0; i < n; i++) {
\t\tfor (int j = 0; j < n; j++)
\t\t\tcout << ans[i][j];
\t\tcout << '\n';
\t}
\treturn 0;
}