#include <iostream>
#include <vector>

using namespace std;
using tp = long long int;

signed main() {
  tp n, m, k, rd = 1;
  scanf("%lld%lld%lld", &n, &m, &k);
  vector<pair<tp, tp>> r(m);
  vector<vector<tp>> re(n + 1);
  vector<tp> jump(n + 1), rc(n + 1, 0), rl(n + 1, 0), tar(n + 1);
  for (auto&& i : r) {
    scanf("%lld%lld", &i.first, &i.second);
  }
  for (tp i = 1; i <= n; ++i) {
    jump[i] = i;
    for (auto&& j : r) {
      if (jump[i] >= j.first && jump[i] <= j.second) {
        jump[i] = j.second + j.first - jump[i];
      }
    }
  }
  for (tp i = 1; i <= n; ++i) {
    if (!rc[i]) {
      tp nl = jump[i];
      rc[i] = rd;
      re[rd].push_back(i);
      rl[jump[i]] = i != jump[i] ? 1 : rl[jump[i]];
      while (nl != i) {
        rc[nl] = rd;
        re[rd].push_back(nl);
        if (jump[nl] != i)
          rl[jump[nl]] = rl[nl] + 1;
        nl = jump[nl];
      }
      ++rd;
    }
  }
  for (tp i = 1; i <= n; ++i) {
    tar[re[rc[i]][(rl[i] + k) % re[rc[i]].size()]] = i;
  }
  for (tp i = 1; i <= n; ++i) {
    printf("%lld
", tar[i]);
  }
  return 0;
}