#include <iostream>

using namespace std;

int main() {
\tint t;
\tcin >> t;
\twhile (t--) {
\t\tint n;
\t\tcin >> n;
\t\tstring s;
\t\tcin >> s;
\t\tint st = n - 1;
\t\tchar first = 'R';
\t\tfor (int i = 0; i < n; i++) {
\t\t\tif (s[i] != '?') {
\t\t\t\tst = i - 1;
\t\t\t\tfirst = s[i] == 'R' ? 'B' : 'R';
\t\t\t\tbreak;
\t\t\t}
\t\t}
\t\tfor (int i = st; i >= 0; i--) {
\t\t\ts[i] = first;
\t\t\tfirst = first == 'R' ? 'B' : 'R';
\t\t}
\t\tfor (int i = st + 1; i < n; i++) {
\t\t\tif (s[i] == '?') {
\t\t\t\ts[i] = s[i - 1] == 'R' ? 'B' : 'R';
\t\t\t}
\t\t}
\t\tcout << s << '\n';
\t}
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