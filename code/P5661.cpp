#include <iostream>

using namespace std;

int tim, num, k, tail = 0, p[100002], t[100002], m;

int main() {
  int n, pri;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m >> pri >> tim;
    if (!m) {
      p[tail] = pri;
      t[tail] = tim;
      tail++;
      num += pri;
    } else {
      bool f = true;
      for (int j = k; j < tail; j++) {
        if (tim - t[j] > 45)
          k = j + 1;
        else if (tim - t[j] <= 45 && pri <= p[j]) {
          p[j] = -1;
          f = false;
          break;
        }
      }
      if (f)
        num += pri;
    }
  }
  cout << num;
  return 0;
}