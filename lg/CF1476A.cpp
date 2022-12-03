#include <iostream>

using namespace std;

int main() {
\tint t;
\tfor (cin >> t; t--;) {
\t\tint n, k, c, sum;
\t\tcin >> n >> k;
\t\tc = n / k;
\t\tif (n % k)
\t\t\tc++;
\t\tsum = k * c;
\t\tcout << sum / n + bool(sum % n) << '\n';
\t}
\treturn 0;
}