#include <iostream>
#include <iomanip>

using namespace std;

int main() {
\tint sum = 0, mark = 0, n;
\tcin >> n;
\tfor (int i = 0; i < n; i++) {
\t\tint m;
\t\tcin >> m;
\t\tsum += m;
\t}
\tmark = sum;
\tfor (int i = 0; i < n; i++) {
\t\tint m;
\t\tcin >> m;
\t\tmark -= m;
\t}
\tcout << fixed << setprecision(6) << (sum * 1.0 / mark + 2);
\treturn 0;
}