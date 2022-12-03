#include <iostream>
#define int unsigned

using namespace std;

template<unsigned size>
class di_set {
public:
\tint b[size];
\tinline void init(const int& n) {
\t\tfor (int i = 1; (b[i] = i) <= n; i++);
\t}

\tinline int find(const int& f) {
\t\treturn b[f] == f ? f : b[f] = find(b[f]);
\t}

\tinline void merge(const int& u, const int& v) {
\t\tb[find(v)] = find(u);
\t}
};

signed main() {
\tint n, m;
\tcin >> n >> m;
\tdi_set<10100> s;
\ts.init(n + 5);
\tfor (int i = 0; i < m; i++) {
\t\tint op, u, v;
\t\tcin >> op >> u >> v;
\t\tif (op == 1)
\t\t\ts.merge(u, v);
\t\telse
\t\t\tcout << (s.find(u) == s.find(v) ? "Y
" : "N
");
\t}
\treturn 0;
}