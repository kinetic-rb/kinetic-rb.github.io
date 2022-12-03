#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
\tint t;
\tfor (cin >> t; t--;) {
\t\tint w, h, n, cnt = 0;
\t\tcin >> w >> h >> n;
\t\twhile (!(w & 1)) {
\t\t\tw >>= 1;
\t\t\tcnt++;
\t\t}
\t\twhile (!(h & 1)) {
\t\t\th >>= 1;
\t\t\tcnt++;
\t\t}
\t\tputs((1 << cnt) >= n ? "YES" : "NO");
\t}
\treturn 0;
}