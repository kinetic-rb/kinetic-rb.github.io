#include <iostream>
#define int long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
\tint n, m, x;
\tcin >> n >> m >> x;
\tfor (int i = 0; i < n; i++) {
\t\tchar op;
\t\tint temp;
\t\tcin >> op >> temp;
\t\top == '1' ? x = (x + temp) % m : x = (x * temp) % m;
\t}
\tcout << x;
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