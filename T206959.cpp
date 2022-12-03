//mirror
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1001, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1}, f[2][4] = {{2, 3, 0, 1}, {3, 2, 1, 0}};
char qwq;
int n, m, a[MAXN][MAXN], ans = -1;

void F(int x, int y, int fx){
\tint js = 0;
\twhile(x >= 1 && x <= n && y >= 1 && y <= m){
\t\tfx = f[a[x][y]][fx];
\t\tx += dx[fx];
\t\ty += dy[fx];
\t\tjs++;
\t}
\tans = max(js, ans);
}

int main(){
//\tfreopen("mirror.in", "r", stdin);
//\tfreopen("mirror.out", "w", stdout);
\tcin >> n >> m;
\tfor(int i = 1; i <= n; i++){
\t\tfor(int j = 1; j <= m; j++){
\t\t\tcin >> qwq;
\t\t\ta[i][j] = (qwq == '/' ? 0 : 1);
\t\t}
\t}
\tfor(int i = 1; i <= m; i++){
\t\tF(1, i, 0);
\t\tF(n, i, 1);
\t} 
\tfor(int j = 1; j <= n; j++){
\t\tF(j, 1, 3);
\t\tF(j, m, 2);
\t}
\tcout << ans;
\treturn 0; 
}