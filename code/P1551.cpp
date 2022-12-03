#include <iostream>

using namespace std;

template<unsigned size>
class di_set {
public:
  unsigned* b = new unsigned[size];
  inline void init(const unsigned& n) {
    for (unsigned i = 1; (b[i] = i) <= n; i++);
  }

  inline unsigned find(const unsigned& f) {
    return b[f] == f ? f : b[f] = find(b[f]);
  }

  inline void merge(const unsigned& u, const unsigned& v) {
    b[find(v)] = find(u);
  }
};

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  di_set<10000> s;
  s.init(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    s.merge(u, v);
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << (s.find(x) == s.find(y) ? "Yes
" : "No
");
  }
  return 0;
}