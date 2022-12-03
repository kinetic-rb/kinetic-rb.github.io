#include <iostream>
#define InPut 0

using namespace std;

inline void FileSwitch(const char* InputFileName) {
#if InPut
  FILE* STREAM;
  freopen_s(&STREAM, InputFileName, "r", stdin);
#endif
}

int main() {
  FileSwitch("#1.in");
  int p1, p2, p3;
  string s;
  cin >> p1 >> p2 >> p3 >> s;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '-' && ((s[i - 1] <= '9' && s[i - 1] >= '0') &&
                            (s[i + 1] <= '9' && s[i + 1] >= '0') ||
                        ((s[i - 1] <= 'z' && s[i - 1] >= 'a') &&
                         (s[i + 1] <= 'z' && s[i + 1] >= 'a')) ||
                        ((s[i - 1] <= 'Z' && s[i - 1] >= 'A') &&
                         (s[i + 1] <= 'Z' && s[i + 1] >= 'A')))) {
      if (s[i - 1] >= s[i + 1])
        cout << '-';
      else if (p3 == 1) {
        for (char t = s[i - 1] + 1; t < s[i + 1]; t++)
          for (int i = 0; i < p2; i++)
            if (p1 == 3)
              putchar('*');
            else if (p1 == 2 && t <= 'z' && t >= 'a')
              putchar(t - 32);
            else if (t <= 'Z' && t >= 'A')
              putchar(t + 32);
            else
              putchar(t);
      } else {
        for (char t = s[i + 1] - 1; t > s[i - 1]; t--)
          for (int i = 0; i < p2; i++)
            if (p1 == 3)
              putchar('*');
            else if (p1 == 2 && t <= 'z' && t >= 'a')
              putchar(t - 32);
            else if (t <= 'Z' && t >= 'A')
              putchar(t + 32);
            else
              putchar(t);
      }
    } else
      cout << s[i];
  return 0;
}