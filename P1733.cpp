#include <iostream>

using namespace std;

int lg[100005];
int n, k;

inline bool small(int ml) {
\tint sum = 0;
\tfor (int i = 0; i < n; i++)
\t\tsum += lg[i] / ml;
\treturn sum >= k;
}

inline void search() {
\tint qloc = 0;
\tfor (int i = 29; i > -1; i--) {
\t\tint loc = qloc + (1 << i);
\t\tif (loc > 1e9)
\t\t    loc = 1e9;
\t\tcout << loc << endl;
\t\tint m;
\t\tcin >> m;
\t\tif (!m)
\t\t\treturn;
\t\tif (m == -1)
\t\t\tqloc = loc;
\t}
\treturn;
}

int main() {
\tios_base::sync_with_stdio(false);
\tsearch();
\treturn 0;
}