#include <iostream>

using namespace std;

template<unsigned size>
class di_set {
public:
  unsigned* b = new unsigned[size];
  inline void init(const unsigned& n) {
    for (unsigned i = 0; (b[i] = i) < n; i++);
  }

  inline unsigned find(const unsigned& f) {
    return b[f] == f ? f : b[f] = find(b[f]);
  }

  inline void merge(const unsigned& u, const unsigned& v) {
    b[find(v)] = find(u);
  }
};

int c[100000], d[100000], f[100000];

int main() {
  int n, m, w;
  cin >> n >> m >> w;
  di_set<100000> s;
  s.init(100000);
  for (int i = 0; i < n; i++)
    cin >> c[i] >> d[i];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    s.merge(--x, --y);
  }
  for (int i = 0; i < n; i++)
    if (s.b[i] != i) {
      d[s.find(i)] += d[i];
      c[s.find(i)] += c[i];
      d[i] = c[i] = 0;
    }
  for (int i = 0; i < n; i++)
    for (int v = w; v >= c[i]; v--)
      f[v] = max(f[v], f[v - c[i]] + d[i]);
  cout << f[w];
  return 0;
}