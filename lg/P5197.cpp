#include <cstdio>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

tp cnt[Hat_N];

signed main() {
\ttp n, MAX = 0;
\tcin >> n;
\tfor (tp i = 1; i < n; ++i) {
\t\ttp u, v;
\t\tcin >> u >> v;
\t\t++cnt[u];
\t\t++cnt[v];
\t}
\tfor (tp i = 1; i <= n; ++i) {
\t\tMAX = max(MAX, cnt[i]);
\t}
\tcout << MAX + 1;
\treturn 0;
}