#include <iostream>

using namespace std;

int main() {
\tint t;
\tfor (cin >> t; t--; cout << '\n') {
\t\tstring x;
\t\tcin >> x;
\t\tchar e = *(x.end() - 1);
\t\tcout << (e == '1' || e == '3' || e == '5' || e == '7' || e == '9' ? "odd" : "even");
\t}
\treturn 0;
}