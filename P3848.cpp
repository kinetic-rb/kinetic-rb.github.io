#include <iostream>

using namespace std;

int n, MAX;
const int dr[][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int mz[101][101];

void dfs(int, int, int);
pair<int, int> getloc(int, int, int, int);

int main() {
\tint sx, sy;
\tcin >> n >> sx >> sy;
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = 1; j <= n; j++) 
\t\t\tcin >> mz[i][j];
\tmz[sx][sy] = 2;
\tdfs(sx, sy, 0);
\tcout << MAX;
\treturn 0;
}

inline void dfs(int x, int y, int lo) {
\tMAX = max(MAX, lo);
\tfor (auto i : dr) {
\t\tint dx = getloc(x, y, i[0], i[1]).first, dy = getloc(x, y, i[0], i[1]).second;
\t\tif (dx > 0 && dy > 0 && dx <= n && dy <= n && !mz[dx][dy] && mz[x + i[0]][y + i[1]] == 1) {
\t\t\tmz[dx][dy] = 2;
\t\t\tdfs(dx, dy, lo + max(abs(dy - y), abs(dx - x)));
\t\t\tmz[dx][dy] = 0;
\t\t}
\t}
}


inline pair<int, int> getloc(int x, int y, int px, int py) {
\tx += px;
\ty += py;
\tdo {
\t\tx += px;
\t\ty += py;
\t} while (x > 0 && y > 0 && x <= n && y <= n && mz[x][y] == 1);
\treturn make_pair(x, y);
}

/*
1 1 0 1 1 0 1
0 1 1 1 0 1 1
1 1 0 1 1 0 1
1 0 1 1 0 1 1
1 0 1 0 1 1 1
1 1 0 1 1 0 1
1 0 1 1 0 1 0

4  3  2
1  0  1  0
1  0  1  1
0  0  0  0
1  1  0  1
*/