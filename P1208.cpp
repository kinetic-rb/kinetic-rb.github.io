#include <iostream>
#include <algorithm>

using namespace std;

struct milk {
\tint p, a;
} mi[5005];

int main() {
\tint n, m, ps = 0;
\tcin >> n >> m;
\tif (!n) {
\t\tfor (int i = 0; i < 9999999; i++);
\t\tcout << 0;
\t\treturn 0;
\t}
\tfor (int i = 0; i < m; i++)
\t\tcin >> mi[i].p >> mi[i].a;
\tstable_sort(mi, mi + m, [](milk x, milk y) {
\t\treturn x.p < y.p;
\t});
\tfor (int i = 0; true; i++) {
\t\tif (n <= mi[i].a) {
\t\t\tps += mi[i].p * n;
\t\t\tbreak;
\t\t}
\t\tn -= mi[i].a;
\t\tps += mi[i].p * mi[i].a;
\t}
\tcout << ps;
\treturn 0;
}