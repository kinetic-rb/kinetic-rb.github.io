//T203608
#include <bits/stdc++.h>

using namespace std;

const int MAXTX = 1e2 + 1, MAXN = 1e3 + 1;
int n, m, x, y, tx, ty;
bool vis[MAXTX][MAXTX];
string s[MAXN];

void shuchu(int xx, int yy, int j){
\tcout << xx << ' ' << yy << endl;
\tfor(int i = 1; i <= n - j; i++){
\t\tcout << "NO
";
\t}
}

bool moni(int &xx, int &yy, int i){
\tint js = 1;
\twhile(xx >= 0 && yy >= 0 && xx <= tx && yy <= ty && js <= m){
\t\tif(vis[xx][yy] || xx <= 0 || yy <= 0 || xx > tx || yy > ty){
\t\t\treturn 0;
\t\t}
\t\tvis[xx][yy] = 1;
\t\tswitch(s[i][js - 1]){
\t\t\tcase 'U': yy--; break;
\t\t\tcase 'L': xx--; break;
\t\t\tcase 'R': xx++; break;
\t\t\tcase 'D': yy++; break;
\t\t}\t\t
\t\tjs++;
\t}
\tif(vis[xx][yy] || xx <= 0 || yy <= 0 || xx > tx || yy > ty){
\t\treturn 0;
\t}
\treturn 1;
}

int main(){
// \tfreopen("10.in", "r", stdin);
// \tfreopen("10.out", "w", stdout);
\tcin >> n >> m >> x >> y >> tx >> ty;
\tfor(int i = 1; i <= n; i++){
\t\tcin >> s[i];
\t}
\tfor(int i = 1; i <= n; i++){
\t\tint xx = x, yy = y;
\t\tif(!moni(xx, yy, i)){
\t\t\tcout << "NO
";
\t\t}
\t\telse{
\t\t\tshuchu(xx, yy, i);
\t\t\treturn 0;
\t\t}
\t\tmemset(vis, 0, sizeof(vis));
\t}
\treturn 0;
}
