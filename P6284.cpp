#include <iostream>

using namespace std;

int main() {
\tint x, n, ans;
\tcin >> x >> n;
\tans = x * n;
\tfor (int i = 0; i < n; i++) {
\t\tint y;
\t\tcin >> y;
\t\tans -= y;
\t}
\tcout << ans + x;
\treturn 0;
}