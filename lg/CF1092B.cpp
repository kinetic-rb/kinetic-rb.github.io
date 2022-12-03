#include <algorithm>
#include <iostream>

using namespace std;
using tp = int32_t;
constexpr tp Hat_N = 103;

tp v[Hat_N];

signed main() {
\ttp n, cnt = 0;
\tcin >> n;
\tfor (tp i = 0; i < n; ++i) {
\t\tcin >> v[i];
\t}
\tstable_sort(v, v + n);
\tfor (tp i = 0; i < n; ++ ++i) {
\t\tcnt += v[i + 1] - v[i];
\t}
\tcout << cnt;
\treturn 0;
}