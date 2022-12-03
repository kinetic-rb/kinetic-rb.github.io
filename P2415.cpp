#include <iostream>
#include <cmath>

using namespace std;

int main() {
\tlong s = 0, n = 0;
  \tfor (int x; cin >> x; s += x)
      n++;
    cout << (long) (s * pow(2, n - 1));
    return 0;
}