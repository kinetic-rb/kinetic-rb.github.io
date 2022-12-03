#include <iostream>
#include <algorithm>

using namespace std;

template<typename Typex>
class barry {
protected:
  int _alocked = 0;
  Typex* elespace;
public:
  barry(const int& size = 0) {
    elespace = new Typex[_alocked = size];
  }

  barry(const int& size, const int& val) {
    elespace = new Typex[_alocked = size];
    for (int i = 0; i < size; i++) {
      elespace[i] = val;
    }
  }

  inline int size() {
    return _alocked;
  }

  inline void resize(const int& size) {
    auto tmp = new Typex[_alocked];
    for (int i = 0; i < _alocked; i++)
      tmp[i] = elespace[i];
    delete[] elespace;
    elespace = new Typex[size];
    for (int i = 0; i < _alocked; i++)
      elespace[i] = tmp[i];
    _alocked = size;
  }

  inline Typex& operator [] (const int& x) {
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

  ~barry() {
    delete[] elespace;
  }
};

struct cor {
  string name;
  int mark;
};

int main() {
  int n;
  cin >> n;
  barry<cor> s;
  for (int i = 0; i < n; i++) {
    string name;
    int mark;
    cin >> mark >> name;
    s.push({ name, mark });
  }
  cout << max_element(s.begin(), s.end(), [](const cor& x, const cor& y) {
    return x.mark < y.mark;
  })->name;
  return 0;
}