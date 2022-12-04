#include <deque>
#include <iostream>
#include <vector>

using namespace std;

template <typename Typex>
class RBTree {
  struct TNode {
    TNode *P, *LC, *RC;
    Typex value;
    long count, size;
    bool color;
  } * root, *null, *memoryPool, *tail, **delNodes;
  long delTop;

  TNode* newNode(const Typex& _value, bool _color) {
    TNode* current;
    current = (delTop ? delNodes[--delTop] : tail++);
    current->value = _value;
    current->P = current->LC = current->RC = null;
    current->size = current->count = 1;
    current->color = _color;
    return current;
  }

  void deleteNode(TNode* current) {
    if (current == null)
      return;
    delNodes[delTop++] = current;
  }

  void maintain(TNode* current) {
    if (current == null)
      return;
    current->size = current->count + current->LC->size + current->RC->size;
  }

  bool getType(TNode* current) { return current->P->RC == current; }

  bool getType(TNode* P, const Typex& value) { return P->value < value; }

  void connect(TNode* P, TNode* current, const bool& type) {
    (type ? P->RC : P->LC) = current;
    current->P = P;
  }

  void rotate(TNode* P, const bool& type) {
    if (P == null)
      return;
    TNode* current = (type ? P->LC : P->RC);
    if (current == null)
      return;
    TNode* grandParent = P->P;
    bool parentType = getType(P);
    connect(P, type ? current->RC : current->LC, !type);
    connect(current, P, type);
    if (P == root)
      root = current;
    connect(grandParent, current, parentType);
    maintain(P);
    maintain(current);
  }

  void updateSize(TNode* current) {
    while (current != null) {
      maintain(current);
      current = current->P;
    }
  }

  void InsertFixup(TNode* current) {
    TNode* uncle;
    bool parentType;
    while (!current->P->color) {
      parentType = getType(current->P);
      uncle = current->P->P;
      uncle = parentType ? uncle->LC : uncle->RC;
      if (!uncle->color) {
        current->P->color = uncle->color = true;
        current->P->P->color = false;
        current = current->P->P;
      } else {
        if (getType(current) != parentType) {
          current = current->P;
          rotate(current, parentType);
        }
        current->P->color = true;
        current->P->P->color = false;
        rotate(current->P->P, !parentType);
      }
    }
    root->color = true;
  }

  void transplant(TNode* u, TNode* v) {
    if (u == root)
      root = v;
    connect(u->P, v, getType(u));
  }

  TNode* minimum(TNode* current) {
    while (current->LC != null)
      current = current->LC;
    return current;
  }

  void RemoveFixup(TNode* current) {
    for (TNode* brother; current != root && current->color;) {
      bool type = getType(current);
      brother = current->P;
      brother = type ? brother->LC : brother->RC;
      if (!brother->color) {
        brother->color = true;
        current->P->color = false;
        rotate(current->P, type);
        brother = current->P;
        brother = type ? brother->LC : brother->RC;
      }
      if (brother->LC->color && brother->RC->color) {
        brother->color = false;
        current = current->P;
      } else {
        if ((type ? brother->LC : brother->RC)->color) {
          (type ? brother->RC : brother->LC)->color = true;
          brother->color = false;
          rotate(brother, !type);
          brother = current->P;
          brother = type ? brother->LC : brother->RC;
        }
        brother->color = current->P->color;
        current->P->color = (type ? brother->LC : brother->RC)->color = true;
        rotate(current->P, type);
        current = root;
      }
    }
    current->color = true;
  }

  TNode* find(const Typex& value) {
    for (TNode* current = root; current != null;)
      if (current->value < value)
        current = current->RC;
      else if (value < current->value)
        current = current->LC;
      else
        return current;
    return null;
  }

  TNode* _Order(long rank) {
    for (TNode* current = root; current != null;) {
      if (current->LC->size < rank) {
        rank -= current->LC->size + current->count;
        if (rank < 1)
          return current;
        current = current->RC;
      } else
        current = current->LC;
    }
    return null;
  }

 public:
  RBTree(const long& _T_Size) : delTop(0) {
    delNodes = new TNode*[_T_Size];
    tail = memoryPool = new TNode[_T_Size];
    null->P = null->LC = null->RC = null = newNode(Typex(), true);
    null->count = null->size = 0;
    root = null;
  }

  void insert(const Typex& value) {
    if (root == null) {
      root = newNode(value, true);
      return;
    }
    TNode *current = root, *P = current->P;
    while (current != null) {
      current->size++;
      if (current->value < value) {
        P = current;
        current = current->RC;
      } else if (value < current->value) {
        P = current;
        current = current->LC;
      } else {
        current->count++;
        return;
      }
    }
    current = newNode(value, false);
    connect(P, current, getType(P, value));
    InsertFixup(current);
  }

  void remove(TNode* z) {
    if (z == null)
      return;
    if (1 < z->count) {
      z->count--;
      updateSize(z);
      return;
    }
    TNode *x, *y = z;
    bool yOriginalColor = y->color;
    if (z->LC == null) {
      x = z->RC;
      transplant(z, z->RC);
    } else if (z->RC == null) {
      x = z->LC;
      transplant(z, z->LC);
    } else {
      y = minimum(z->RC);
      yOriginalColor = y->color;
      x = y->RC;
      if (y->P == z)
        x->P = y;
      else {
        transplant(y, y->RC);
        connect(y, z->RC, true);
      }
      transplant(z, y);
      connect(y, z->LC, false);
      y->color = z->color;
    }
    updateSize(x->P);
    if (yOriginalColor)
      RemoveFixup(x);
    deleteNode(z);
  }

  void remove(const Typex& Val) { remove(find(Val)); }

  long rank(const Typex& value) {
    long leftSize = 1;
    for (TNode* current = root; current != null;)
      if (value < current->value || !(current->value < value))
        current = current->LC;
      else {
        leftSize += current->LC->size + current->count;
        current = current->RC;
      }
    return leftSize;
  }

  const Typex* order(const long& rank) { return &_Order(rank)->value; }

  const Typex* lower_bound(const Typex& Value) { return order(rank(Value)); }

  const Typex* upper_bound(const Typex& Value) {
    const Typex* lb = lower_bound(Value);
    if (Value < *lb)
      return lb;
    return order(rank(Value) + 1);
  }
};

int main() {
  RBTree<pair<long, long>> tree(40000);
  static long num[8005];
  long n, m;
  cin >> n >> m;
  for (long i = 1; i <= n; i++) {
    cin >> num[i];
    tree.insert(make_pair(num[i], i));
  }
  for (long i = 1; i <= m; i++) {
    long op;
    cin >> op;
    if (op == 1) {
      long x, v;
      cin >> x >> v;
      tree.remove(make_pair(num[x], x));
      tree.insert(make_pair(v, x));
      num[x] = v;
    } else {
      long val;
      cin >> val;
      cout << tree.rank(make_pair(num[val], val)) << '\n';
    }
  }
  return 0;
}