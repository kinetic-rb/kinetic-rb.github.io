#include <algorithm>
#include <iostream>

using namespace std;

class Mempool {
  const static int Block_Size = 100024;
  const static int Item_Size = 16;

  struct Item_Node {
    struct Item_Node* next;
    char data[Item_Size - sizeof(Item_Node*)];
  };

  struct Block_Node {
    struct Block_Node* next;
    Item_Node data[Block_Size / Item_Size];
  };

  Block_Node* BlockNodeHead;
  Item_Node* freeItemNodeHead;

 public:
  Mempool() : BlockNodeHead(0), freeItemNodeHead(0) {}
  ~Mempool() {
    for (Block_Node* tmp = BlockNodeHead; tmp; tmp = BlockNodeHead) {
      BlockNodeHead = BlockNodeHead->next;
      delete tmp;
    }
  }

  void* Alloc() {
    if (!freeItemNodeHead) {
      Block_Node* tmpBlockNode = new Block_Node;
      if (!tmpBlockNode) {
        perror("No memory!/n");
        exit(1);
      }
      if (BlockNodeHead) {
        tmpBlockNode->next = BlockNodeHead;
        BlockNodeHead = tmpBlockNode;
      } else {
        BlockNodeHead = tmpBlockNode;
        BlockNodeHead->next = NULL;
      }
      freeItemNodeHead = &(tmpBlockNode->data[0]);
      int i;
      for (i = 0; i < Block_Size / Item_Size - 1; i++)
        tmpBlockNode->data[i].next = &(tmpBlockNode->data[i + 1]);
      tmpBlockNode->data[i].next = NULL;
    }
    Item_Node* allocItemNode = freeItemNodeHead;
    freeItemNodeHead = freeItemNodeHead->next;
    return allocItemNode;
  }

  void Free(void* p) {
    Item_Node* tmpItemNode = static_cast<Item_Node*>(p);
    tmpItemNode->next = freeItemNodeHead;
    freeItemNodeHead = tmpItemNode;
  }
};

int main() {
  Mempool pool;
  int* l = static_cast<int*>(pool.Alloc());
  long long n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> l[i];
  for (int i = 0; i < n - 1; sum += l[++i]) {
    stable_sort(l + i, l + n);
    l[i + 1] += l[i];
  }
  cout << sum;
  return 0;
}