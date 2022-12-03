#include <iostream>

using namespace std;

inline void move(int x, char a, char b, char c) {
\tif (!x)
\t\treturn;
\tmove(x - 1, a, c, b);
\tprintf("%d %c %c
", x, a, b);
\tmove(x - 1, c, b, a);
}

int main() {
\tint n;
\tcin >> n;
\tmove(n, 'A', 'B', 'C');
\treturn 0;
}