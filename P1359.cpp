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

memory<int> f;

int main() {
  int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
      int x;
            cin >> x;
            if (!f[j] || f[j] > f[i] + x)
                f[j] = f[i] + x;
        }
    cout << f[n];
    return 0;
}