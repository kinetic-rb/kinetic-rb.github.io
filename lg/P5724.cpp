#include <iostream>

using namespace std;

int main() {
\tint n, MAX = -0x7fffffff, MIN = 0x7fffffff;
\tcin >> n;
\tfor (int i = 0; i < n; i++) {
\t\tint x;
\t\tcin >> x;
\t\tMIN = min(MIN, x);
\t\tMAX = max(MAX, x);
\t}
\tcout << MAX - MIN;
\treturn 0;
}