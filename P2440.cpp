#include <iostream>
#define int long long

using namespace std;

int lg[100005];
int n, k;

inline bool small(int ml) {
\tint sum = 0;
\tfor (int i = 0; i < n; i++)
\t\tsum += lg[i] / ml;
\treturn sum >= k;
}

inline int search() {
\tint qloc = 0;
\tfor (int i = 25; i > -1; i--) {
\t\tint loc = qloc + (1 << i);
\t\tif (small(loc)) {
\t\t\tqloc = loc;
\t\t}
\t}
\treturn qloc;
}

signed main() {
\tios_base::sync_with_stdio(false);
\tcin >> n >> k;
\tfor (int i = 0; i < n; i++)
\t\tcin >> lg[i];
\tcout << search();
\treturn 0;
}