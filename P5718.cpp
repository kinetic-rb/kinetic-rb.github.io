#include <iostream>
#include <algorithm>

using namespace std;

int num[101];

int main() {
\tint n;
\tcin >> n;
\tfor (int i = 0; i < n; i++)
\t\tcin >> num[i];
\tcout << *min_element(num, num + n);
\treturn 0;
}