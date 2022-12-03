#include <iostream>
#include <vector>

using namespace std;

int s[5005], t[5005];

int main() {
\tvector<bool> ap(1000005);
\tint n;
\tcin >> n;
\tfor (int i = 0; i < n; i++) {
\t\tcin >> s[i];
\t\tfor (int j = 0; j < i; j++) {
\t\t\tap[abs(s[i] - s[j])] = true;
\t\t}
\t}
\twhile (ap[n++]);
\tcout << --n;
\treturn 0;
}