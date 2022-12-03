#include <iostream>

using namespace std;

int num[101];

int main() {
\tint n;
\tcin >> n;
\tfor (int i = 0; i < n; i++)
\t\tcin >> num[i];
\tfor (int i = 0; i < n; i++) {
\t\tint cnt = 0;
\t\tfor (int j = 0; j < i; j++)
\t\t\tif (num[j] < num[i])
\t\t\t\tcnt++;
\t\tcout << cnt << ' ';
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
\t\|____________|       \|___|  |___|
*/