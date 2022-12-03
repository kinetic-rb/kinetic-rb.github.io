#include <iostream>
#include <string>

using namespace std;

string go() {
\tstring s = "", x;
\tchar c;
\tint d;
\twhile (cin >> c) {
\t\tif (c == '[') {
\t\t\tcin >> d;
\t\t\tx = go();
\t\t\twhile (d--)
\t\t\t\ts += x;
\t\t} else if (c == ']')
\t\t\treturn s;
\t\telse s += c;
\t}
\treturn s;
}

int main() {
\tcout << go();
\treturn 0;
}