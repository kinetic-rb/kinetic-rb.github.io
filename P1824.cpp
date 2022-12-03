#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1000010], n, c;

inline bool p(const int &d) {
\tregister int k = 0, last = -0x3fffffff;
\tfor (register int i = 1; i <= n; i++) {
\t\tif (a[i] - last >= d) {
\t\t\tlast = a[i];
\t\t\tk++;
\t\t}
\t}
\treturn k >= c;
}

int main() {
\tios_base::sync_with_stdio(false);
\tcin >> n >> c;
\tfor (register int i = 1; i <= n; i++)
\t\tcin >> a[i];
\tstable_sort(a + 1, a + n + 1);
\tregister int l = 0, r = a[n], ans = -0x7fffffff, mid;
\twhile (l <= r) {
\t\tmid = l + ((r - l) >> 1);
\t\tif (p(mid)) {
\t\t\tans = max(ans, mid);
\t\t\tl = mid + 1;
\t\t}
\t\telse
\t\t\tr = mid - 1;
\t}
\tcout << ans;
\treturn 0;
}