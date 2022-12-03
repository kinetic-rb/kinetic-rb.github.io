#include <cstring>
#include <iostream>

using namespace std;

int d[1001], c[1001],
    f[1001][1001]; /* f[i][j] \u8868\u793a\u5728\u7b2c i \u5929\u5230\u8fbe\u57ce\u5e02 j \u7684\u6700\u5c0f\u75b2\u52b3\u503c */

int main() {
  memset(f, 0x7f, sizeof f);
  int n, m, res = 0x7fffffff;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", d + i);
  for (int i = 1; i <= m; i++)
    scanf("%d", c + i);
  for (int i = 1; i <= m; i++)
    f[i][1] = d[1] * c[i];
  for (int i = 2; i <= n; i++)
    for (int j = i; j <= m;
         j++) { /* \u8f6c\u79fb\u65b9\u7a0b : f[j][i] = min(f[j][i],
                   min([f[k][i - 1], f[k][j - 1])]) + d[i] * c[j] */
      int MIN = 0x7fffffff;
      for (int k = i - 1; k < j; k++)
        MIN = min(MIN, f[k][i - 1]);
      f[j][i] = min(f[j][i], MIN + d[i] * c[j]);
    }
  for (int i = 1; i <= m; i++)
    res = min(res, f[i][n]);
  printf("%d", res);
  return 0;
}