#include <iostream>
#include <algorithm>

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

  virtual inline unsigned size() {
    return _alocked;
  }

  virtual inline void resize(const unsigned& size) {
    auto tmp = new Typex[_alocked];
    for (unsigned i = 0; i < _alocked; i++)
      tmp[i] = elespace[i];
    delete[] elespace;
    elespace = new Typex[size];
    for (unsigned i = 0; i < _alocked; i++)
      elespace[i] = tmp[i];
    _alocked = size;
  }

  virtual inline void operator () (const unsigned& size) {
    delete[] elespace;
    elespace = new Typex[_alocked = size];
  }

  virtual inline void operator () (const unsigned& size, const Typex& val) {
    delete[] elespace;
    elespace = new Typex[_alocked = size];
    for (unsigned i = 0; i < size; i++) {
      elespace[i] = val;
    }
  }

  virtual inline Typex& operator [] (const unsigned& x) {
    return elespace[x];
  }

  virtual inline void push(const Typex& val) {
    resize(_alocked + 1);
    elespace[_alocked - 1] = val;
  }

  virtual inline void pop() {
    resize(_alocked - 1);
  }

  virtual inline Typex* begin() {
    return elespace;
  }

  virtual inline Typex* end() {
    return elespace + _alocked;
  }

  virtual inline bool empty() {
    return _alocked;
  }

  ~memory() {
    delete[] elespace;
  }
};

int a[509][509];
memory<int> b, f;

int main() {
  int n;
  cin >> n;
  b(n);
  f(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[j] = a[i][j];
    }
    stable_sort(b.begin(), b.end());
    f[i] = b[n - 2];
  }
  printf("1
%d", *max_element(f.begin(), f.end()));
  return 0;
}