#include <iostream>

using namespace std;

int main() {
\tint t;
\tfor (cin >> t; t--; puts("")) {
\t\tint n;
\t\tstring a;
\t\tcin >> n >> a;
\t\tfor (int i = 0; i < n; i++) {
\t\t\t\tif (!i) {
\t\t\t\t\tcout << 1;
\t\t\t\t\ta[i]++;
\t\t\t\t} else {
\t\t\t\t\tif (a[i - 1] == a[i] + 1)
\t\t\t\t\t\tcout << '0';
\t\t\t\t\telse
\t\t\t\t\t\tcout << '1', a[i]++;
\t\t\t}
\t\t}
\t}
\treturn 0;
}