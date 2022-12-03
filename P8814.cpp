#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#define ra __Read_int()

using namespace std;
using tp = long long;

tp __Read_int() {
\ttp x;
\tscanf("%lld", &x);
\treturn x;
}

tp get(tp w, tp a, tp b, tp c) {
\treturn (-b + w * sqrt(b * b - 4 * a * c)) / (2 * a);
}

signed main() {
\ttp k = ra;
\twhile (k--) {
\t\ttp b = ra, e = ra, d = ra, a = b - e * d + 2;
\t\ttp p = get(1, -1, a, -b), q = get(-1, -1, a, -b);
\t\tif (max(p, q) > b || min(p, q) < -b || b != p * q || e * d != (p - 1) * (q - 1) + 1) {
\t\t\tputs("NO");
\t\t} else {
\t\t\tprintf("%lld %lld
", min(p, q), max(p, q));
\t\t}
\t} 
\treturn 0;
}