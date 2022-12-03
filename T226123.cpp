#include <cstring>
#include <iostream>

using namespace std;
using tp = intmax_t;

template <typename Typex>
class RHeap {
\tTypex* ele;
\tunsigned long long size, Msize;

 public:
  RHeap() : size(0), Msize(2) { ele = new Typex[500005]; }

  void push(int x) {
    ele[++size] = x;
    up(size);
  }

  void up(int x) {
    while (x > 1 && ele[x] < ele[x >> 1]) {
      swap(ele[x], ele[x >> 1]);
      x >>= 1;
    }
  }

  void pop() {
    swap(ele[1], ele[size--]);
    down(1);
  }

  void down(int x) {
    for (int t = x;; x = t) {
      if (x << 1 <= size && ele[x << 1] < ele[t]) {
        t = x << 1;
      }
      if (x << 1 < size && ele[x << 1 | 1] < ele[t]) {
        t = x << 1 | 1;
      }
      if (t == x) {
        return;
      }
      swap(ele[x], ele[t]);
    }
  }

  const Typex& top() {
    return ele[1];
  }
};

signed main() {
  RHeap<tp> h;
  tp n;
  cin >> n;
  while (n--) {
    string op;
    cin >> op;
    if (op == "push") {
      tp x;
      cin >> x;
      h.push(x);
    } else if (op == "top") {
      cout << h.top() << '\n';
    } else {
      h.pop();
    }
  }
\treturn 0;
}