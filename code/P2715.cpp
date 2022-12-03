#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a, b;
char c, ch;

int main() {
  c = getchar();
  while (c == ' ')
    c = getchar();
  if (c == '?') {
    c = getchar();
    while (c == ' ')
      c = getchar();
    cin >> a >> ch >> b;
    if (c == '+') {
      printf("%.2lf
", double(b) - double(a));
      return 0;
    }
    if (c == '-') {
      printf("%.2lf
", double(b) + double(a));
      return 0;
    }
    if (c == '*') {
      printf("%.2lf
", double(b) / double(a));
      return 0;
    }
    if (c == '/') {
      printf("%.2lf
", double(b) * double(a));
      return 0;
    }
  }
  else {
    while (c >= '0' && c <= '9')
      a = a * 10 + c - '0', c = getchar();
    while (c == ' ')
      c = getchar();
    ch = c;
    c = getchar();
    while (c == ' ')
      c = getchar();
    if (c == '?') {
      cin >> c >> b;
      if (ch == '+') {
        printf("%.2lf
", double(b) - double(a));
        return 0;
      }
      if (ch == '-') {
        printf("%.2lf
", double(a) - double(b));
        return 0;
      }
      if (ch == '*') {
        printf("%.2lf
", double(b) / double(a));
        return 0;
      }
      if (ch == '/') {
        printf("%.2lf
", double(a) / double(b));
        return 0;
      }
    }
    else {
      while (c <= '9' && c >= '0')
        b = b * 10 + c - '0', c = getchar();
      if (ch == '+') {
        printf("%.2lf
", double(a) + double(b));
        return 0;
      }
      if (ch == '-') {
        printf("%.2lf
", double(a) - double(b));
        return 0;
      }
      if (ch == '*') {
        printf("%.2lf
", double(a) * double(b));
        return 0;
      }
      if (ch == '/') {
        printf("%.2lf
", double(a) / double(b));
        return 0;
      }
    }
  }
  return 0;
}