#include <iostream>

using namespace std;

inline static int qpew(int a, int n, int m) {
\tif (n == 1) {
\t\treturn a % m;
\t}
\tif (!n) {
\t\treturn 1;
\t}
\tint r = qpew(a, n >> 1, m);
\tr = r * r % m;
\treturn n & 1 ? a * r % m : r;
}

int main() {
\tint t, a, n, m;
\tfor (cin >> t; t--; cout << qpew(a, n, m) << '\n') {
\t\tcin >> a >> n >> m;
\t}
\treturn 0;
}

/*
 ___       ___         ___________
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
    \|____________|       \|___|  |___|
*/