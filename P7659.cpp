#include <iostream>

using namespace std;

int num[24];

int main() {
\tint MAX = 0;
\tfor (int i = 0; i < 8; i++)
\t\tcin >> num[i], num[i + 8] = num[i];
\tfor (int i = 0; i < 16; i++) {
\t\tint sum = 0;
\t\tfor (int j = i; j < i + 4; j++)
\t\t\tsum += num[j];
\t\tMAX = max(MAX, sum);
\t}
\tcout << MAX;
\treturn 0;
} 