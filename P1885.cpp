#include <iostream>
#include <algorithm>

using namespace std;

int a[25] = {3};

inline char Do(int i, int n) {
\tif (!i)
\t\treturn n == 1 ? 'm' : 'o';
\tif (n <= a[i - 1])
\t\treturn Do(i - 1, n);
\tif (n > a[i] - a[i - 1])
\t\treturn Do(i - 1, n - a[i] + a[i - 1]);
\treturn n == a[i - 1] + 1 ? 'm' : 'o';
}

int main() {
\tint n, l = 0;
\tfor (cin >> n; a[l] <= n; l++) {
\t\ta[l + 1] = (a[l] * 2 + l + 4);
\t}
\tcout << Do(l, n);
\treturn 0;
}