#include <iostream>

using namespace std;

int m, n, cnt;

inline void dfs(int idx, int sum, int last) {
\tif (idx == n) {
\t\tif (sum == m)
\t\t\tcnt++;
\t\treturn;
\t}
\tfor (int i = last; i + sum <= m; i++)
\t\tdfs(idx + 1, sum + i, i);
}

int main() {
\tint t;
\tfor (cin >> t; t--; cnt = 0) {
\t\tcin >> m >> n;
\t\tdfs(0, 0, 0);
\t\tcout << cnt << '\n';
\t}
  return 0;
}