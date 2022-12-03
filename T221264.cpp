#include<iostream>
using namespace std;
const long long M = 1e9 + 7;
long long s[100005];
long long n, t, l, r, b;
inline int power(int a, int b) {
\tint ans = 1;
\twhile (b) {
\t\tif (b & 1) {
\t\t\tans = 1ll * ans * a % 1000000007;
\t\t}
\t\tb >>= 1;
\t\ta = 1ll * a * a % 1000000007;
\t}
\treturn ans;
}

int main() {
\tcin >> n >> t >> b;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> s[i];
\t\ts[i] = (s[i - 1] * b + s[i]) % M;
\t}
\tfor (int i = 1; i <= t; i++) {
\t\tcin >> l >> r;
\t\tcout << (s[r] - (s[l - 1] * power(b, (r - l) + 1) + M) % M + M) % M << endl;
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