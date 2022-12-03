#include <iostream>
#include <vector>

using namespace std;
using tp = long long;

signed main() {
\ttp n, ba, bb, MIN = -1ull / 2;
\tcin >> n >> ba >> bb;
\tvector<tp> a(n), b(n), c(n);
\tvector<vector<tp>> f(403, vector<tp>(403, -1ull / 2));
\tf[0][0] = 0;
\tfor (tp i = 0; i < n; ++i) {
\t\tcin >> a[i] >> b[i] >> c[i];
\t}
\tfor (tp i = 0; i < n; ++i) {
\t\tfor (tp j = 400; j >= a[i]; --j) {
\t\t\tfor (tp k = 400; k >= b[i]; --k) {
\t\t\t\tif (f[j - a[i]][k - b[i]] != -1ull / 2) {
\t\t\t\t\tf[j][k] = min(f[j][k], f[j - a[i]][k - b[i]] + c[i]);
\t\t\t\t}
\t\t\t}
\t\t}
\t}
\tfor (tp i = 1; i * max(ba, bb) <= 400; ++i) {
\t\tMIN = min(MIN, f[i * ba][i * bb]);
\t}
\tcout << (MIN == -1ull / 2 ? -1 : MIN);
\treturn 0;
} 