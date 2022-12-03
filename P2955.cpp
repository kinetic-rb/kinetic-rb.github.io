#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--; cout << '\n') {
    string x;
    cin >> x;
    char e = *(x.end() - 1);
    cout << (e == '1' || e == '3' || e == '5' || e == '7' || e == '9' ? "odd" : "even");
  }
  return 0;
}