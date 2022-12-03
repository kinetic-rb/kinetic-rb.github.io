#include <iostream>

using namespace std;

bool T;

inline bool ces(string s) {
  int x = 0;
  for (auto& i : s) {
    if (i == '(')
      x++;
    else if (x)
      x--;
    else
      return false;
  }
  return !x;
}

inline void to_end(string s, char A, char B, char C) {
  for (auto& i : s)
    switch (i) {
      case 'A':
        i = A;
        break;
      case 'B':
        i = B;
        break;
      default:
        i = C;
    }
  if (ces(s))
    T = true;
}

int main() {
  int t;
  for (cin >> t; t--;) {
    T = false;
    string s;
    cin >> s;
    to_end(s, '(', '(', ')');
    to_end(s, '(', ')', '(');
    to_end(s, '(', ')', ')');
    to_end(s, ')', '(', '(');
    to_end(s, ')', '(', ')');
    to_end(s, ')', ')', '(');
    puts(T ? "yEs" : "nO");
  }
  return 0;
}