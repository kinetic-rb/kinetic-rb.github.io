#include <iostream>
#include <algorithm>

using namespace std;

long long sum[1005], a[1005];
long long MAX, n, c;

inline void dfs(int n, long long x) {
\tif (x > c)
\t\treturn;
\tif (sum[n - 1] + x <= c) {
\t\tMAX = max(MAX, sum[n - 1] + x);
\t\treturn;
\t}
\tMAX = max(MAX, x);
\tfor (int i = 0; i < n; i++)
\t\tdfs(i, x + a[i]);
\treturn;
}

int main() {
\tcin >> n >> c;
\tfor (int i = 0; i < n; i++) {
\t\tcin >> a[i];
\t\tsum[i] = sum[i - 1] + a[i];
\t}
\tdfs(n, 0);
\tcout << MAX;
\treturn 0;
}