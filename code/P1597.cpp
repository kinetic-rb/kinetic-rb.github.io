#include <iostream>

using namespace std;

char d[300];
int a[10] = { 0 };

int main() {
  cin >> d;
  for (int i = 0; d[i]; i++)
    if (d[i + 1] == ':' && d[i + 2] == '=') {
      if (d[i + 3] >= '0' && d[i + 3] <= '9')
        a[d[i] - 'a'] = d[i + 3] - '0';
      if (d[i + 3] >= 'a' && d[i + 3] <= 'z')
        a[d[i] - 'a'] = a[d[i + 3] - 'a'];
    }
  cout << a[0] << ' ' << a[1] << ' ' << a[2];
  return 0;
}