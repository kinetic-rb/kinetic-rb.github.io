#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int num[101];

int main() {
\tint t;
\tfor (cin >> t; t--;) {
\t\tmemset(num, 0, sizeof num);
\t\tint ans = 0, n;
\t\tcin >> n;
\t\tfor (int i = 0; i < n; i++) {
\t\t\tint x;
\t\t\tcin >> x;
\t\t\tnum[x]++;
\t\t}
\t\tcout << *max_element(num, num + 101) << '\n';
\t}
\treturn 0;
}