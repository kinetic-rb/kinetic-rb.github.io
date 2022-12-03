#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
using i32 = int;
using i64 = long long;
using ui32 = unsigned int;
using ui64 = unsigned long long;

i32 main() {
  i64 n, k;
  scanf("%lld %lld", &n, &k);
  while (k--)
    if (n % 10)
      --n;
    else
      n /= 10;
  printf("%lld", n);
  return 0;
}