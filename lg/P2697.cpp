#include <iostream>

using namespace std;

int ps[1000001];

int main() {
    ios::sync_with_stdio(false);
\tint n = 0, MAX = 0;
\tfor (char ch; cin >> ch; ps[n] = ps[n - 1] + (ch == 'R' ? 1 : -1))
\t\tn++;
\tfor (int i = 1; i <= n; i++) {
\t\tfor (int j = i; j <= n; j++) {
\t\t\tif (!(ps[j] - ps[i - 1]))
\t\t\t\tMAX = max(MAX, j - i + 1);
\t\t}
\t}
\tcout << MAX;
\treturn 0;
}