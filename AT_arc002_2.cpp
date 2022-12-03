#include <iostream>

using namespace std;

int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(false);
    int y, m, d, t;
    char ch;
  cin >> y >> ch >> m >> ch >> d;
  a[2] += (!(y % 4) && y % 100 || !(y % 400));
  while (y % (d * m)) {
    if (++d > a[m]) {
      m++;
      d = 1;
    }
    if (m > 12)  {
      y++;
      m = 1;
    }  
    }
    cout << y << '/' << m / 10 << m % 10 << '/' << d / 10 << d % 10 << endl;
  return 0;
}
