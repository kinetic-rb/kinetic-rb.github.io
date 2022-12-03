#include <iostream>

using namespace std;
using tp = intmax_t;

template <typename Typex>
class RHeap {
  Typex* ele;
  uintmax_t Size, MSize;

 public:
  RHeap() : Size(0), MSize(1) { ele = new Typex; }

  void push(const Typex& _Val) {
    if (++Size == MSize) {
      Typex* Rele = new Typex[MSize <<= 1];
      for (uintmax_t i = 1; i < Size; ++i) {
        Rele[i] = ele[i];
      }
      delete ele;
      ele = Rele;
    }
    ele[Size] = _Val;
    for (uintmax_t x = Size; x > 1 && ele[x] < ele[x >> 1]; x >>= 1) {
      swap(ele[x], ele[x >> 1]);
    }
  }

  void pop() {
    swap(ele[1], ele[Size--]);
    for (uintmax_t x = 1, y = 1;; x = y) {
      if (x << 1 <= Size && ele[x << 1] < ele[y]) {
        y = x << 1;
      }
      if (x << 1 < Size && ele[x << 1 | 1] < ele[y]) {
        y = x << 1 | 1;
      }
      if (y == x) {
        return;
      }
      swap(ele[x], ele[y]);
    }
  }

  const Typex& top() { return ele[1]; }

  uintmax_t size() { return Size; }
};

template <typename Typex>
class Removealbe_Heap {
  RHeap<Typex> ele, removed;

 public:
  void push(const Typex& _Val) { ele.push(_Val); }

  const Typex& top() {
    while (removed.size() && !(removed.top() < ele.top()) &&
           !(ele.top() < removed.top())) {
      ele.pop();
      removed.pop();
    }
    return ele.top();
  }

  void remove(const Typex& _Val) { removed.push(_Val); }

  void pop() { ele.pop(); }
};

tp val[500005];

struct RHNode {
  tp x;

  RHNode() = default;
  RHNode(tp _x) : x(_x) {}
  bool operator<(const RHNode& comp) const { return x > comp.x; }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Removealbe_Heap<tp> MIN;
  Removealbe_Heap<RHNode> MAX;
  tp n, cnt = 0;
  cin >> n;
  while (n--) {
    string op;
    cin >> op;
    if (op == "min") {
      cout << MIN.top() << '\n';
      MAX.remove(MIN.top());
      MIN.pop();
    } else if (op == "max") {
      cout << MAX.top().x << '\n';
      MIN.remove(MAX.top().x);
      MAX.pop();
    } else {
      tp x;
      cin >> x;
      MIN.push(x);
      MAX.push(x);
    }
  }
  return 0;
}