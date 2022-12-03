#include <iostream>
#include <functional>

using namespace std;

int main() {
  int x;
  cin >> x;
  function<void(int)> PRINT = [&](int n) -> void {
    if (n == 4) {
      cout << "oooo****--";
      for (int i = 0; i < x - n; i++)
        cout << "o*";
      cout << "
ooo--***o*";
      for (int i = 0; i < x - n; i++)
        cout << "o*";
      cout << "
ooo*o**--*";
      for (int i = 0; i < x - n; i++)
        cout << "o*";
      cout << "
o--*o**oo*";
      for (int i = 0; i < x - n; i++)
        cout << "o*";
      cout << "
o*o*o*--o*";
      for (int i = 0; i < x - n; i++)
        cout << "o*";
      cout << "
--o*o*o*o*";
      for (int i = 0; i < x - n; i++)
        cout << "o*";
      cout << '\n';
    } else {
      for (int i = 0; i < n; i++)
        cout << "o";
      for (int i = 0; i < n; i++)
        cout << "*";
      cout << "--";
      for (int i = 0; i < x - n; i++)
        cout << "o*";
      cout << '\n';
      for (int i = 0; i < n - 1; i++)
        cout << "o";
      cout << "--";
      for (int i = 0; i < n - 1; i++)
        cout << "*";
      cout << "o*";
      for (int i = 0; i < x - n; i++)
        cout << "o*";
      cout << '\n';
      PRINT(n - 1);
    }
  };
  PRINT(x);
  return 0;
}