#include <iostream>

using namespace std;

template<unsigned size>
class di_set {
public:
\tunsigned* b = new unsigned[size];
\tinline void init(const unsigned& n) {
\t\tfor (unsigned i = 0; (b[i] = i) < n; i++);
\t}

\tinline unsigned find(const unsigned& f) {
\t\treturn b[f] == f ? f : b[f] = find(b[f]);
\t}

\tinline void merge(const unsigned& u, const unsigned& v) {
\t\tb[find(v)] = find(u);
\t}
};

int c[100000], d[100000], f[100000];

int main() {
\tint n, m, w;
\tcin >> n >> m >> w;
\tdi_set<100000> s;
\ts.init(100000);
\tfor (int i = 0; i < n; i++)
\t\tcin >> c[i] >> d[i];
\tfor (int i = 0; i < m; i++) {
\t\tint x, y;
\t\tcin >> x >> y;
\t\ts.merge(--x, --y);
\t}
\tfor (int i = 0; i < n; i++)
\t\tif (s.b[i] != i) {
\t\t\td[s.find(i)] += d[i];
\t\t\tc[s.find(i)] += c[i];
\t\t\td[i] = c[i] = 0;
\t\t}
\tfor (int i = 0; i < n; i++)
\t\tfor (int v = w; v >= c[i]; v--)
\t\t\tf[v] = max(f[v], f[v - c[i]] + d[i]);
\tcout << f[w];
\treturn 0;
}