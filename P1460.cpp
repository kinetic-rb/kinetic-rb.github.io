#include <iostream>

using namespace std;

int sum[101], need[101], s[101][101], r[101], o[101];
int n, k, MIN = 0x7fffffff, ans;

inline void dfs(int idx) {
\tbool l = true;
\tfor (int i = 1; i <= n; i++) {
\t\tif (sum[i] < need[i]) {
\t\t\tl = false;
\t\t\tbreak;
\t\t}
\t}
\tif (l) {
\t\tif (ans < MIN) {
\t\t\tMIN = ans;
\t\t\tfor (int i = 1; i <= MIN; i++)
\t\t\t\tr[i] = o[i];
\t\t}
\t\treturn;
\t}
\to[++ans] = idx;
\tfor (int i = 1; i <= n; i++)
\t\tsum[i] = sum[i] + s[idx][i];
\tfor (int i = 1; i <= k - idx + 1; i++)
\t\tdfs(idx + i);
\tans--;
\tfor (int i = 1; i <= n; i++)
\t\tsum[i] = sum[i] - s[idx][i];
}

int main() {
    ios::sync_with_stdio(false);
\tcin >> n;
\tfor (int i = 1; i <= n; i++)
\t\tcin >> need[i];
\tcin >> k;
\tfor (int i = 1; i <= k; i++)
\t\tfor (int j = 1; j <= n; j++)
\t\t\tcin >> s[i][j];
\tdfs(0);
\tcout << MIN - 1 << ' ';
\tfor (int i = 2; i <= MIN; i++)
\t\tcout << r[i] << ' ';
\treturn 0;
}