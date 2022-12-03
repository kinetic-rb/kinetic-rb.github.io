#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int cho[300] = {1};
int n;

inline void dfs(int s, int t) {
\tfor (int i = cho[t - 1]; i <= s; i++)
\t\tif (i < n) {
\t\t\tcho[t] = i;
\t\t\ts -= i;
\t\t\tif (!s) {
\t\t\t\tfor (int i = 1; i < t; i++)
\t\t\t\t\tcout << cho[i] << '+';
\t\t\t\tcout << cho[t] << '\n';
\t\t\t}
\t\t\telse
\t\t\t\tdfs(s, t + 1);
\t\t\ts += i;
\t\t}
}

int main() {
\tcin >> n;
\tdfs(n, 1);
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