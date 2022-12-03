#include <iostream>
#include <functional>

using namespace std;

int main() {
\tint x;
\tcin >> x;
\tfunction<void(int)> PRINT = [&](int n) -> void {
\t\tif (n == 4) {
\t\t\tcout << "oooo****--";
\t\t\tfor (int i = 0; i < x - n; i++)
\t\t\t\tcout << "o*";
\t\t\tcout << "
ooo--***o*";
\t\t\tfor (int i = 0; i < x - n; i++)
\t\t\t\tcout << "o*";
\t\t\tcout << "
ooo*o**--*";
\t\t\tfor (int i = 0; i < x - n; i++)
\t\t\t\tcout << "o*";
\t\t\tcout << "
o--*o**oo*";
\t\t\tfor (int i = 0; i < x - n; i++)
\t\t\t\tcout << "o*";
\t\t\tcout << "
o*o*o*--o*";
\t\t\tfor (int i = 0; i < x - n; i++)
\t\t\t\tcout << "o*";
\t\t\tcout << "
--o*o*o*o*";
\t\t\tfor (int i = 0; i < x - n; i++)
\t\t\t\tcout << "o*";
\t\t\tcout << '\n';
\t\t} else {
\t\t\tfor (int i = 0; i < n; i++)
\t\t\t\tcout << "o";
\t\t\tfor (int i = 0; i < n; i++)
\t\t\t\tcout << "*";
\t\t\tcout << "--";
\t\t\tfor (int i = 0; i < x - n; i++)
\t\t\t\tcout << "o*";
\t\t\tcout << '\n';
\t\t\tfor (int i = 0; i < n - 1; i++)
\t\t\t\tcout << "o";
\t\t\tcout << "--";
\t\t\tfor (int i = 0; i < n - 1; i++)
\t\t\t\tcout << "*";
\t\t\tcout << "o*";
\t\t\tfor (int i = 0; i < x - n; i++)
\t\t\t\tcout << "o*";
\t\t\tcout << '\n';
\t\t\tPRINT(n - 1);
\t\t}
\t};
\tPRINT(x);
\treturn 0;
}