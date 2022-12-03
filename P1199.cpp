#include <iostream>
#include <algorithm>

using namespace std;

int a[509][509], b[509], f[509];

int main() {
\tint n;
\tcin >> n;
\tfor (int i = 0; i < n; i++) {
\t\tfor (int j = i + 1; j < n; j++) {
\t\t\tcin >> a[i][j];
\t\t\ta[j][i] = a[i][j];
\t\t}
\t}
\tfor (int i = 0; i < n; i++) {
\t\tfor (int j = 0; j < n; j++) {
\t\t\tb[j] = a[i][j];
\t\t}
\t\tstable_sort(b, b + n);
\t\tf[i] = b[n - 2];
\t}
\tprintf("1
%d", *max_element(f, f + n));
\treturn 0;
}