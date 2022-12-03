#include <iostream>

using namespace std;

int main() {
\tint t;
\tfor (cin >> t; t--;) {
\t\tint x;
\t\tcin >> x;
\t\tputs(x % 2020 > x / 2020 ? "nO" : "yEs");
\t}
\treturn 0;
}