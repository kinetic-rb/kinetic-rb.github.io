#include <iostream>

using namespace std;

int num[1000000];

int main() {
\tint n, cnt = 0, temp = 2;
\tcin >> n;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> num[i];
\t}
\tfor (int i = 1; i < n; i++) {
\t\tif (num[i] > num[i - 1]) {
\t\t\ttemp++;
\t\t\tcontinue;
\t\t}
\t\tcnt = max(cnt, temp);
\t\ttemp = 1;
\t}
\tcout << cnt;
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