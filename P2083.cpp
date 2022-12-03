#include <iostream>
#include <cmath>

using namespace std;

template<typename Typex>
class memory {
  unsigned _alocked;
  Typex* elespace;
public:
  using iterator = Typex*;
  memory(const unsigned& size = 0) {
    elespace = new Typex[_alocked = size];
  }

  memory(const unsigned& size, const Typex& val) {
    elespace = new Typex[_alocked = size];
    for (unsigned i = 0; i < size; i++) {
      elespace[i] = val;
    }
  }

  inline unsigned size() {
    return _alocked;
  }

  inline void resize(const unsigned& size) {
    auto tmp = new Typex[_alocked];
    for (unsigned i = 0; i < _alocked; i++)
      tmp[i] = elespace[i];
    delete[] elespace;
    elespace = new Typex[size];
    for (unsigned i = 0; i < _alocked; i++)
      elespace[i] = tmp[i];
    _alocked = size;
  }

  inline void operator () (const unsigned& size) {
    delete[] elespace;
    elespace = new Typex[_alocked = size];
  }

  inline void operator () (const unsigned& size, const Typex& val) {
    delete[] elespace;
    elespace = new Typex[_alocked = size];
    for (unsigned i = 0; i < size; i++) {
      elespace[i] = val;
    }
  }

  inline Typex& operator [] (const unsigned& x) {
    if (x >= _alocked)
      resize(x + 1);
    return elespace[x];
  }

  inline void push(const Typex& val) {
    resize(_alocked + 1);
    elespace[_alocked - 1] = val;
  }

  inline void pop() {
    resize(_alocked - 1);
  }

  inline Typex* begin() {
    return elespace;
  }

  inline Typex* end() {
    return elespace + _alocked;
  }

  inline bool empty() {
    return _alocked;
  }

  ~memory() {
    delete[] elespace;
  }
};

int n, m, v, zx, zy;

struct house {
  int x, y;
};

memory<house> a[1001];

inline int dfs(int c, int f, int s, int zs) {
  if (c == zx && f == zy)
    return s;
  if (zs > n * m)
    return 0x7fffffff;
  dfs(a[c][f].x, a[c][f].y, s + v * (abs(a[c][f].x - c)), zs + 1);
}

int main() {
  int MIN = 0x7fffffff;
  cin >> n >> m >> v >> zx >> zy;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j].x >> a[i][j].y;
  for (int i = 1; i <= m; i++)
    MIN = min(dfs(1, i, 0, 0), MIN);
  MIN == 0x7fffffff ? cout << "impossible" : cout << MIN;
  return 0;
}