#include <iostream>

using namespace std;

int main() {
\tint n, cnt = 0;
\tfor (cin >> n; n; cnt++)
\t\tn /= 2;
\tcout << cnt;
\treturn 0;
}