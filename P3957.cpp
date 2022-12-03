#include <cstring>
#include <iostream>

using namespace std;

struct CE {
  long long poi, dis;
} num[500001];

long long f[500001];

template <typename comp>
long long fs(const long long& MAX, const comp& cmp) {
  long long qloc = 0;
  for (long long pew = MAX; pew; pew >>= 1)
    if (cmp(qloc + pew))
      qloc += pew;
  return qloc;
}

signed main() {
  long long n, d, k;
  scanf("%lld %lld %lld", &n, &d, &k);
  for (long long i = 1; i <= n; i++)
    scanf("%lld %lld", &num[i].dis, &num[i].poi);
  long long ans = fs(1 << 15,
                     [&](long long x) {
                       long long mb = x + d, lb = max(d - x, 1ll);
                       memset(f, -0x7f, sizeof f);
                       *f = 0;
                       for (long long i = 1; i <= n; i++)
                         for (long long j = i - 1; j >= 0; j--) {
                           if (num[i].dis - num[j].dis < lb)
                             continue;
                           if (num[i].dis - num[j].dis > mb)
                             break;
                           f[i] = max(f[i], f[j] + num[i].poi);
                           if (f[i] >= k)
                             return false;
                         }
                       return true;
                     }) +
                  1;
  printf("%lld", ans == 1 << 16 ? -1 : ans);
  return 0;
}

/*
                          //\
                          // |
///////\   //////\        ///////\  //\   //\  //////\
//  __//\ //  __//\       //  __//\ // |  // |//  __//\
// |  // |// /  // |      // |  // |// |  // |// /  // |
// |  // |// |  // |      // |  // |// |  // |// |  // |
// |  // |\//////  |      ///////  |\//////  |\/////// |
\__|  \__| \______/       \_______/  \______/  \____// |
                                              //\   // |
                                              \//////  |
                                               \______/
*/