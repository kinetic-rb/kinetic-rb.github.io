#include <stdio.h>

int qp[5][5];
int md;

int IDA(int);
inline int IDA(int dep) {
  if (dep == md) {
    for (int i = 1; i < 4; i++)
      for (int j = 1; j < 4; j++)
        if (!qp[i][j])
          return 0;
    return 1;
  }
  for (int i = 1; i < 4; i++)
    for (int j = 1; j < 4; j++) {
      qp[i][j] ^= 1;
      qp[i - 1][j] ^= 1;
      qp[i + 1][j] ^= 1;
      qp[i][j - 1] ^= 1;
      qp[i][j + 1] ^= 1;
      if (IDA(dep + 1))
        return 1;
      qp[i][j] ^= 1;
      qp[i - 1][j] ^= 1;
      qp[i + 1][j] ^= 1;
      qp[i][j - 1] ^= 1;
      qp[i][j + 1] ^= 1;
    }
  return 0;
}

int main() {
  for (int i = 1; i < 4; i++)
    for (int j = 1; j < 4; j++)
      scanf("%d", &qp[i][j]);
  for (;; md++)
    if (IDA(0)) {
        printf("%d", md);
      break;
    }
  return 0;
}