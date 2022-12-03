#include <iostream>
#include <array>

using namespace std;

array<bool, 200000> ac;

int main() {
   int n, m;
   bool NONE = false;
   cin >> n >> m;
   for (int p = 0; p <= m; p++)
      for (int q = 0; q <= m; q++)
         ac[p * p + q * q] = true;
   for (int b = 1; b * (n - 1) <= m * m * 2; b++)
      for (int a = 0; (a + b * (n - 1)) <= m * m * 2; a++) {
         if (!ac[a]) {
            continue;
         }
         bool flag = true;
         int num = a;
         for (int i = 2; i <= n; i++) {
            num += b;
            if (!ac[num]) {
               flag = false;
               break;
            }
         }
         if (flag) {
            NONE = true;
            cout << a << ' ' << b << '\n';
         }
      }
   if (!NONE) {
      cout << "NONE";
   }
   return 0;
}