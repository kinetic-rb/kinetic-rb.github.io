#include <iostream>

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

  inline void operator () (const unsigned& size = 0) {
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

int f[505][505];

int main() {
    memory<int> a, b, c;
  int l, m, n, k;
  cin >> m >> n >> k;
  for (int i = 1; i <= k; i++)
    cin >> a[i] >> b[i] >> c[i];
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= a[i]; j--)
      for (l = n; l >= b[i]; l--)
        f[j][l] = max(f[j][l], f[j - a[i]][l - b[i]] + c[i]);
  cout << f[m][n];
  return 0;
}
