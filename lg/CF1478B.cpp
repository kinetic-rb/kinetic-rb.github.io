#include <iostream>

using namespace std;

int main(){
  int t;
  for (cin >> t; t--;) {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
      bool f = true;
      int x;
      cin >> x;
      if (x >= 10 * d) {
      \tputs("yEs");
        continue;
      } else
        while (x >= 0) {
          x -= d;
          if (!(x % 10)) {
      \t\t\tputs("YeS");
          \tf = false;
          \tbreak;
          }
        }
      if (f)
      \tputs("nO");
  \t}
  }
  return 0;
}