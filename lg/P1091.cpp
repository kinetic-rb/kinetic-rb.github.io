#include <iostream>
#include <algorithm>

using namespace std;

int up[1001], down[1001], num[1001];

int main() {
\tint n, MAX = 0;
\tcin >> n;
\tfor (int i = 0; i < n; i++) {
\t\tcin >> num[i];
\t\tup[i] = down[i] = 1;
\t}
\tfor (int i = 0; i < n; i++)
\t\tfor (int j = 0; j < i; j++) {
\t\t\tif (num[j] < num[i])
\t\t\t\tup[i] = max(up[i], up[j] + 1);
\t\t}
\tfor (int i = n - 1; i > -1; i--)
\t\tfor (int j = i; j < n; j++) {
\t\t\tif (num[j] < num[i])
\t\t\t\tdown[i] = max(down[i], down[j] + 1);
\t\t}
\tfor (int i = 0; i < n; i++) {
\t\tMAX = max(MAX, up[i] + down[i] - 1);
\t}
\tcout << n - MAX;
\treturn 0;
}