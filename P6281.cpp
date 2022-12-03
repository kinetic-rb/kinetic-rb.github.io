#include <algorithm>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

struct Rs {
\ttp l, r;
\t
\tbool operator<(const Rs& comp) const {
\t\treturn l < comp.l;
\t}
} p[Hat_N];
tp n, m;

bool check(tp d) {
\ttp ml = 0, loc = p->l;
\tfor (tp i = 0; i < n; ++i) {
\t\twhile (loc > p[ml].r) {
\t\t\tif (++ml == m) {
\t\t\t\treturn 0;
\t\t\t}
\t\t}
\t\tloc = max(loc, p[ml].l);
\t\tloc += d;
\t}
\treturn 1;
}

tp fs() {
\ttp qloc = 0;
\tfor (tp loc = 1ll << 60; loc; loc >>= 1) {
\t\tif (check(qloc + loc)) {
\t\t\tqloc += loc;
\t\t}
\t}
\treturn qloc;
}

signed main() {
\tscanf("%lld%lld", &n, &m);
\tfor (tp i = 0; i < m; ++i) {
\t\tscanf("%lld%lld", &p[i].l, &p[i].r);
\t}
\tstable_sort(p, p + m);
\tprintf("%lld
", fs());
\treturn 0;
}