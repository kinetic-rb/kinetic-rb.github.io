#include <iostream>

using namespace std;

template<unsigned size>
class di_set {
public:
\tunsigned* b = new unsigned[size];
\tinline void init(const unsigned& n) {
\t\tfor (unsigned i = 1; (b[i] = i) <= n; i++);
\t}

\tinline unsigned find(const unsigned& f) {
\t\treturn b[f] == f ? f : b[f] = find(b[f]);
\t}

\tinline void merge(const unsigned& u, const unsigned& v) {
\t\tb[find(v)] = find(u);
\t}
};

int main() {
\tint n, m, q;
\tcin >> n >> m >> q;
\tdi_set<10000> s;
\ts.init(n);
\tfor (int i = 0; i < m; i++) {
\t\tint u, v;
\t\tcin >> u >> v;
\t\ts.merge(u, v);
\t}
\tfor (int i = 0; i < q; i++) {
\t\tint x, y;
\t\tcin >> x >> y;
\t\tcout << (s.find(x) == s.find(y) ? "Yes
" : "No
");
\t}
\treturn 0;
}