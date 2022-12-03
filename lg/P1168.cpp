#include <iostream>
#include <vector>

using namespace std;
using tp = intmax_t;

template <typename Typex>
class Tree {
  double _Alpha;

  struct TNode;
  using iterator = TNode*;
  struct TNode {
    bool exist;
    Typex _Value;
    iterator LC, RC;
    uintmax_t size, cover;

    TNode() = default;
    TNode(const Typex& _Key) : _Value(_Key) { exist = size = cover = 1; }

    void _ReCalc() {
      size = LC->size + RC->size + exist;
      cover = LC->cover + RC->cover + 1;
    }
  } * null, *root;

  iterator _NewNode(const Typex& _Value) {
    iterator p = new TNode(_Value);
    p->LC = p->RC = null;
    return p;
  }

  void _Travel(iterator p, vector<iterator>& x) {
    if (p == null) {
      return;
    }
    _Travel(p->LC, x);
    if (p->exist) {
      x.push_back(p);
      _Travel(p->RC, x);
    } else {
      _Travel(p->RC, x);
      delete p;
      p = null;
    }
  }

  iterator _Divide(vector<iterator>& x, uintmax_t l, uintmax_t r) {
    if (l < r) {
      uintmax_t mid = (l + r) >> 1;
      iterator p = x[mid];
      p->LC = _Divide(x, l, mid);
      p->RC = _Divide(x, mid + 1, r);
      p->_ReCalc();
      return p;
    }
    return null;
  }

  void _Rebuild(iterator& p) {
    static vector<iterator> x;
    x.clear();
    _Travel(p, x);
    p = _Divide(x, 0, x.size());
  }

  iterator* _Insert(iterator& p, const Typex& _Value) {
    if (p == null) {
      p = _NewNode(_Value);
      return &null;
    }
    ++p->size;
    ++p->cover;
    iterator* res = _Insert(
        (_Value < p->_Value || !(p->_Value < _Value) ? p->LC : p->RC), _Value);
    if ((p->LC->cover > p->cover * _Alpha) ||
        (p->RC->cover > p->cover * _Alpha)) {
      return &p;
    }
    return res;
  }

  void _Remove(iterator& p, uintmax_t k) {
    --p->size;
    uintmax_t offset = p->LC->size + p->exist;
    if (p->exist && offset == k) {
      p->exist = 0;
    } else {
      k > offset ? _Remove(p->RC, k - offset) : _Remove(p->LC, k);
    }
  }

 public:
  Tree(double Alpha) : _Alpha(Alpha) {
    null = new TNode;
    null->LC = null->RC = null;
    null->cover = null->size = null->exist = 0;
    root = null;
  }

  void insert(const Typex& _Value) {
    iterator* res = _Insert(root, _Value);
    if (*res != null) {
      _Rebuild(*res);
    }
  }

  uintmax_t size() { return root->size; }

  uintmax_t rank(const Typex& _Value) {
    iterator now = root;
    uintmax_t sum = 1;
    while (now != null) {
      if (_Value < now->_Value || !(now->_Value < _Value)) {
        now = now->LC;
      } else {
        sum += now->LC->size + now->exist;
        now = now->RC;
      }
    }
    return sum;
  }

  const Typex& order(uintmax_t _Value) {
    iterator now = root;
    while (now != null) {
      if (now->LC->size + 1 == _Value && now->exist) {
        return now->_Value;
      }
      if (now->LC->size >= _Value) {
        now = now->LC;
      } else {
        _Value -= now->LC->size + now->exist;
        now = now->RC;
      }
    }
    return Typex();
  }

  void remove(const Typex& k) {
    _Remove(root, rank(k));
    if (root->size < root->cover * _Alpha) {
      _Rebuild(root);
    }
  }
};

signed main() {
  Tree<int> tree(0.7);
  tp n, x;
  cin >> n >> x;
  tree.insert(x);
  cout << x;
  for (--n; -- --n >= 0; cout << '\n' << tree.order(tree.size() + 1 >> 1)) {
    tp x, y;
    cin >> x >> y;
    tree.insert(x);
    tree.insert(y);
  }
  return 0;
}