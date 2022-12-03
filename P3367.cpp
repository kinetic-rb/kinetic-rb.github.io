#include <iostream>
#define int unsigned

using namespace std;

template<unsigned size>
class di_set {
public:
  int b[size];
  inline void init(const int& n) {
    for (int i = 1; (b[i] = i) <= n; i++);
  }

  inline int find(const int& f) {
    return b[f] == f ? f : b[f] = find(b[f]);
  }

  inline void merge(const int& u, const int& v) {
    b[find(v)] = find(u);
  }
};

signed main() {
  int n, m;
  cin >> n >> m;
  di_set<10100> s;
  s.init(n + 5);
  for (int i = 0; i < m; i++) {
    int op, u, v;
    cin >> op >> u >> v;
    if (op == 1)
      s.merge(u, v);
    else
      cout << (s.find(u) == s.find(v) ? "Y
" : "N
");
  }
  return 0;
}