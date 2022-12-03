#include <iostream>
#include <string>

using namespace std;

string go() {
  string s = "", x;
  char c;
  int d;
  while (cin >> c) {
    if (c == '[') {
      cin >> d;
      x = go();
      while (d--)
        s += x;
    } else if (c == ']')
      return s;
    else s += c;
  }
  return s;
}

int main() {
  cout << go();
  return 0;
}