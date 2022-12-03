#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, m, p;
int num[505], f[502][502];

int dfs(const int& idx, const int& delay) {
  if (f[idx][delay] + 1)
    return f[idx][delay];
  if (idx == 1)
    return delay;
  int Nmin = 0x7fffffff;
  for (int i = 0; i < p; i++) {
    if (num[idx - 1] + i == num[idx] + delay && dfs(idx - 1, i) + delay < Nmin)
      Nmin = dfs(idx - 1, i) + delay;
    if (num[idx - 1] + i + m <= num[idx] + delay &&
        dfs(idx - 1, i) + delay < Nmin)
      Nmin = dfs(idx - 1, i) + delay;
  }
  return f[idx][delay] = Nmin;
}

int main() {
  int MIN = 0x7fffffff;
  memset(f, -1, sizeof f);
  scanf("%d %d", &n, &m);
  p = m << 1;
  for (int i = 1; i <= n; i++)
    scanf("%d", num + i);
  stable_sort(num + 1, num + n + 1);
  for (int i = 0; i < p; i++)
    if (dfs(n, i) < MIN)
      MIN = dfs(n, i);
  printf("%d", MIN);
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