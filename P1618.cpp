#include <iostream>
#include <cstring>

using namespace std;

int main() {
  bool t[10], no = true;
  int x = 100, y = 100, z = 100, tx, ty, tz, A, B, C;
  int s[9];
  cin >> A >> B >> C;
  for (; x < 1000; x++)
    for (y = 100; y < 1000; y++)
      for (z = 100; z < 1000; z++) {
        tx = x * B * C;
        ty = y * A * C;
        tz = z * A * B;
        if (tx == ty)
          if (ty == tz)
            if (tx == ty)
              if (ty == tz) {
                memset(t, false, sizeof(t));
                t[x % 10 - 1] = t[x / 10 % 10 - 1] = t[x / 100 - 1] = t[y % 10 - 1] = t[y / 10 % 10 - 1] = t[y / 100 - 1] = t[z % 10 - 1] = t[z / 10 % 10 - 1] = t[z / 100 - 1] = true;
                if (t[0] && t[1] && t[2] && t[3] && t[4] && t[5] && t[6] && t[7] && t[8]) {
                  cout << x << " " << y << " " << z << '\n';
                  no = false;
                }
              }
      }
  if (no)
    cout << "No!!!";
  return 0;
}