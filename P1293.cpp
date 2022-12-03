#include <iostream>

using namespace std;

struct AC {
\tint a, b;
\tstring s;
} m[10005];

int main() {
\tstring end;
\tlong long num = 0, ans = 0x7fffffffffffffff, n = 0;
\twhile (cin >> m[n].a >> m[n].b >> m[n].s)
\t\tif (!m[n].b)
\t\t\tbreak;
\t\telse
\t\t\tn++;
\tfor (int i = 0; i <= n; i++) {
\t\tnum = 0;
\t\tfor (int j = 0; j <= n; j++)
\t\t\tnum = num + (m[j].a * abs(m[j].b - m[i].b));
\t\tif (ans >= num) {
\t\t\tans = num;
\t\t\tend = m[i].s;
\t\t}
\t}
\tcout << end << ' ' << ans;
\treturn 0;
}