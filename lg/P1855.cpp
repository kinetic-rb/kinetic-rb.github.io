#include <iostream>

using namespace std;

int n, tim, mon;
int t[101], m[101], f[201][201];

int main() {
\tcin >> n >> mon >> tim;
\tfor (int i = 1; i <= n; i++)
\t\tcin >> m[i] >> t[i];
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = mon; j >= m[i]; j--)
\t\t\tfor (int k = tim; k >= t[i]; k--)
\t\t\t\tf[j][k] = max(f[j][k], f[j - m[i]][k - t[i]] + 1);
\tcout << f[mon][tim];
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