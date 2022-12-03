#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 1003;

char mz[Hat_N][Hat_N];
bool vis[Hat_N][Hat_N], Geted[Hat_N][Hat_N];
tp dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
tp n;

tp dfs(tp x, tp y) {
\tvis[x][y] = 1;
\ttp sum = 1;
\tfor (auto&& i : dir) {
\t\ttp dx = x + 0[i], dy = y + 1[i];
\t\tif (dx < 1 || dy < 1 || dx > n || dy > n) {
\t\t\tcontinue;
\t\t}
\t\tif (mz[dx][dy] == '#' && !vis[dx][dy]) {
\t\t\tsum += dfs(dx, dy);
\t\t}
\t}
\treturn sum;
}

tp Get(tp x, tp y) {
\tGeted[x][y] = 1;
\ttp sum = 4;
\tfor (auto&& i : dir) {
\t\ttp dx = x + 0[i], dy = y + 1[i];
\t\tif (dx < 1 || dy < 1 || dx > n || dy > n) {
\t\t\tcontinue;
\t\t}
\t\tif (mz[dx][dy] == '#') {
\t\t\t--sum;
\t\t\tif (!Geted[dx][dy]) {
\t\t\t\tsum += Get(dx, dy);
\t\t\t}
\t\t}
\t}
\treturn sum;
}

signed main() {
\ttp MAX = 0, RES = 1145141919810;
\tcin >> n;
\tfor (tp i = 1; i <= n; ++i) {
\t\tfor (tp j = 1; j <= n; ++j) {
\t\t\tcin >> mz[i][j];
\t\t}
\t}
\tfor (tp i = 1; i <= n; ++i) {
\t\tfor (tp j = 1; j <= n; ++j) {
\t\t\tif (mz[i][j] == '#' && !vis[i][j]) {
\t\t\t\tMAX = max(MAX, dfs(i, j));
\t\t\t}
\t\t}
\t}
\tmemset(vis, 0, sizeof vis);
\tfor (tp i = 1; i <= n; ++i) {
\t\tfor (tp j = 1; j <= n; ++j) {
\t\t\tif (mz[i][j] == '#' && !vis[i][j] && dfs(i, j) == MAX) {
\t\t\t\tRES = min(RES, Get(i, j));
\t\t\t}
\t\t}
\t}
\tcout << MAX << ' ' << RES;
\treturn 0;
}
