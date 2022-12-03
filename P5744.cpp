#include <iostream>

using namespace std;

int main() {
\tint n;
\tfor (cin >> n; n--; ) {
\t\tstring name;
\t\tint y, mark;
\t\tcin >> name >> y >> mark;
\t\tcout << name << ' ' << ++y << ' ' << min(600, mark * 6 / 5) << '\n';
\t}
\treturn 0;
}