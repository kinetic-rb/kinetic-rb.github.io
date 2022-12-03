#include <iostream>

using namespace std;

int main() {
\tint n, sum = 0;
\tcin >> n;
\tfor (int i = 1; i < n; i++)
\t\tsum += i;
\tcout << sum + n;
\treturn 0;
}