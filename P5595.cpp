#include <iostream>
#include <cmath>

using namespace std;

int main() {
\tstring c, x, y;
\tint X = 0, Y = 0, loc;
\tcin >> c;
\tfor (loc = c.size() - 1; c[loc] == 'Z' && loc > -1; loc--);
\tfor (; loc > -1; loc--)
\t\tif (c[loc] == 'Z') {
\t\t\tcout << -1;
\t\t\treturn 0;
\t\t}
\tfor (int i = 0; i < c.size(); i++) {
\t\tif (c[i] == 'X') {
\t\t\tx.push_back('9');
\t\t\ty.push_back('1');
\t\t} else if (c[i] == 'Y') {
\t\t\ty.push_back('9');
\t\t\tx.push_back('1');
\t\t} else {
\t\t\tx.push_back('5');
\t\t\ty.push_back('5');
\t\t}
\t}
\tcout << x << '\n' << y;
\treturn 0;
}