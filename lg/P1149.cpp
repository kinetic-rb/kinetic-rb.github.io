#include <iostream>
#define int long long

using namespace std;

int to[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

inline int SUM(int x) {
\tint sum;
\tfor (sum = to[x % 10]; x /= 10; sum += to[x % 10]);
\treturn sum;
}

signed main() {
\tint n, cnt = 0;
\tcin >> n;
\tfor (int A = 0; SUM(A) < n; A++) {
\t\tfor (int B = 0; SUM(A) + SUM(B) < n + 10; B++) {
\t\t\tint C = A + B;
\t\t\tif (n == SUM(C) + SUM(A) + SUM(B) + 4)
\t\t\t\tcnt++;
\t\t}
\t}
\tcout << cnt;
\treturn 0;
}