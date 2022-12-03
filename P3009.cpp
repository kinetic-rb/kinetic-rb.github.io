#include <iostream>

using namespace std;

int val[100001];

int main() {
\tint n, MAX = -0x7fffffff;
\tcin >> n;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> val[i] ;
\t\tMAX = max(val[i] = max(val[i], val[i] + val[i - 1]), MAX);
\t}
\tcout << MAX;
\treturn 0;
}

/*
 ___       ___         ___________
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
\t\|____________|       \|___|  |___|
*/