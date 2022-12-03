#include <iostream>

using namespace std;

int main() {
\tunsigned long long n, ans = 0;
\tcin >> n;
\tfor (long long i = 0; i < n; i++) {
\t\tstatic long long b = 0, a;
\t\tcin >> a;
\t\tif (a > b)
\t\t\tans += (a - b);
\t\tb = a;
\t}
\tcout << ans;
\treturn 0;
}