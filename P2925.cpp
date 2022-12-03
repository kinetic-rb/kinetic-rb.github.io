#include <iostream>

using namespace std;

int f[50001], v[5001];

int main() {
\tint c, h;
\tcin >> c >> h;
\tfor (int i = 0; i < h; i++) {
\t\tcin >> v[i];
\t}
\tfor (int i = 0; i < h; i++) {
\t\tfor (int j = c; j >= v[i]; j--) {
\t\t\tf[j] = max(f[j], f[j - v[i]] + v[i]);
\t\t}
\t\tif (f[c] == c) {
\t\t\tcout << c;
\t\t\treturn 0;
\t\t}
\t}
\tcout << f[c];
\treturn 0;
}