#include <stdio.h>

const int y[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
  int x, z;
  scanf("%d%d", &x, &z);
  if (z == 2 && ((!(x % 4) && (x % 100)) || (!(x % 400)))) {
    printf("29");
    return 0;
  }
  printf("%d", y[--z]);
  return 0;
}