#include <iostream>

using namespace std;

int cnt[10];

int main() {
\tint n, m;
\tfor (cin >> n >> m; n <= m; n++) {
\t\tfor (int temp = n; temp; temp /= 10)
\t\t\tcnt[temp % 10]++;
\t}
\tfor (auto& i : cnt)
\t\tcout << i << ' ';
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