//perimeter
#include <iostream>

using namespace std;

const int MAXN = 105, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, xx, yy, ans;
bool a[MAXN][MAXN], vis[MAXN][MAXN];

void dfs(int x, int y){
\tif(x < 0 || x > 101 || y < 0 || y > 101 || vis[x][y]){
\t\treturn;
\t}
\tif(a[x][y]){
\t\tans++;
\t\treturn;
\t}
\tvis[x][y] = 1;
\tfor(int i = 0; i < 4; i++){
\t\tdfs(x + dx[i], y + dy[i]);
\t}
}

int main(){
//\tfreopen("perimeter.in", "r", stdin);
//\tfreopen("perimeter.out", "w", stdout);
\tcin >> n;
\tfor(int i = 1; i <= n; i++){
\t\tcin >> xx >> yy;
\t\ta[xx][yy] = 1;
\t}
\tdfs(0, 0);
\tcout << ans;
\treturn 0;
}
