#include <iostream>

using namespace std;

int a[25][3];
bool flag[25];

int x, ans;

inline void dfs(int s){
\tif (s > x) {
\t\tans++;
\t\treturn;
\t}
\tif (!flag[a[s][1]]) {
\t\tflag[a[s][1]] = true;
\t\tdfs(s + 1);
\t\tflag[a[s][1]] = false;
\t}
\tif (!flag[a[s][2]]) {
\t\tflag[a[s][2]] = true;
\t\tdfs(s + 1);
\t\tflag[a[s][2]] = false;
\t}
}

int main() {
\tcin >> x;
\tfor (int i=1;i<=x;i++)
\t\tcin >> a[i][1] >> a[i][2];
\tif (x)
\t\tdfs(1);
\tcout<<ans;
\treturn 0;
}