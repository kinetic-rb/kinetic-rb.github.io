#include <cstdio>
#include <queue>

using namespace std;
using i32 = int;
using i64 = long long;
using ui32 = unsigned int;
using ui64 = unsigned long long;

i32 main() {
  i64 n, k, x;
  priority_queue<i64, deque<i64>, greater<i64>> heap;
  scanf("%lld %lld", &n, &k);
  for (i64 t; n--; heap.push(t))
    scanf("%lld", &t);
  if (!k) {
    printf("%lld", (heap.top() < 2) ? -1ll : heap.top() - 1);
    return 0;
  }
  while (--k)
    heap.pop();
  x = heap.top();
  heap.pop();
  if (heap.size() && heap.top() == x) {
    printf("-1");
    return 0;
  }
  printf("%lld", x);
  return 0;
}