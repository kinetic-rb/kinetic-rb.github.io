#include <iostream>
#include <cstring>

using namespace std;

int map[350][350], dist[350][350];
int m, MIN = 0x7fffffff;

void dfs(int x, int y, int t) {
\tif (map[x][y] <= t || t >= MIN || t >= dist[x][y])
\t\treturn;
\tdist[x][y] = t;
\tif (map[x][y] == 0x7f7f7f7f) {
\t\tMIN = min(t, MIN);
\t\treturn;
\t}
\tdfs(x + 1, y, t + 1);
\tif (x > 0)
\t\tdfs(x - 1, y, t + 1);
\tdfs(x, y + 1, t + 1);
\tif (y > 0)
\t\tdfs(x, y - 1, t + 1);
}

int main() {
\tmemset(map, 0x7f, sizeof map);
\tmemset(dist, 0x7f, sizeof dist);
\tcin >> m;
\tfor (int i = 0; i < m; i++) {
\t\tint x, y, t;
\t\tcin >> x >> y >> t;
\t\tmap[x][y] = min(map[x][y], t);
\t\tmap[x + 1][y] = min(map[x + 1][y], t);
\t\tif (x > 0)
\t\t\tmap[x - 1][y] = min(map[x - 1][y], t);
\t\tmap[x][y + 1] = min(map[x][y + 1], t);
\t\tif (y > 0)
\t\t\tmap[x][y - 1] = min(map[x][y - 1], t);
\t}
\tdfs(0, 0, 0);
\tcout << (MIN == 0x7fffffff ? -1 : MIN);
\treturn 0;
}