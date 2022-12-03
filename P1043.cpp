#include <iostream>

using namespace std;

int num[105], f[55],
    __9__[15] = {9, 81, 729, 6561, 59409, 531441, 4782969, 43046721, 387420489};
int n, m, MIN = 0x7fffffff, MAX = -0x7fffffff;

void dfs(const int& idx, const int& x, const int& sum, const int& mul) {
  if (mul >= MIN && mul * __9__[m - idx] <= MAX)
    return;
  if (x > n) {
    if (idx == m) {
      int res = (((sum % 10) + 10) % 10) * mul;
      if (res < MIN)
        MIN = res;
      if (res > MAX)
        MAX = res;
    }
    return;
  }
  dfs(idx, x + 1, sum + f[x], mul);
  if (idx != m)
    dfs(idx + 1, x + 1, f[x], (((sum % 10) + 10) % 10) * mul);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", num + i);
    num[n + i] = num[i];
  }
  int t = n << 1, sptr = 1, eptr = n;
  for (t++; eptr < t; sptr++, eptr++) {
    for (int i = sptr; i <= eptr; i++)
      f[i - sptr + 1] = num[i];
    dfs(1, 2, f[1], 1);
  }
  printf("%d
%d", MIN, MAX);
  return 0;
}

/*
                          $$\
                          $$ |
$$$$$$$\   $$$$$$\        $$$$$$$\  $$\   $$\  $$$$$$\
$$  __$$\ $$  __$$\       $$  __$$\ $$ |  $$ |$$  __$$\
$$ |  $$ |$$ /  $$ |      $$ |  $$ |$$ |  $$ |$$ /  $$ |
$$ |  $$ |$$ |  $$ |      $$ |  $$ |$$ |  $$ |$$ |  $$ |
$$ |  $$ |\$$$$$$  |      $$$$$$$  |\$$$$$$  |\$$$$$$$ |
\__|  \__| \______/       \_______/  \______/  \____$$ |
                                              $$\   $$ |
                                              \$$$$$$  |
                                               \______/
*/