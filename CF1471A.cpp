#include <cstring>
#include <cmath>
#include <iostream>
#define int long long

using namespace std;

int num[100001];

signed main() {
\tint t;
\tfor (cin >> t; t--;) {
\t\tint n, x, num1 = 0, num2 = 0;
\t\tcin >> n >> x;
\t\tfor (int i = 0; i < n; i++) {
\t\t\tint b;
\t\t\tcin >> b;
\t\t\tnum1 += (long long)ceil(b * 1.0 / x);
\t\t\tnum2 += b;
\t\t}
\t\tcout << (long long)ceil(num2 * 1.0 / x) << ' ' << num1 << '\n';
\t}
\treturn 0;
}