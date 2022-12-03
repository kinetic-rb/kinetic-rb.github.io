#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> ac;
  char c = '#';
  int s = 0, x, y;
  while (c != '@') {
    cin >> c;
    switch (c) {
      case '+' :
          x = ac.top();
          ac.pop();
          y = ac.top();
          ac.pop();
          ac.push(x + y);
          break;
      case '-' :
          x = ac.top();
          ac.pop();
          y = ac.top();
          ac.pop();
          ac.push(y - x);
          break;
      case '*' :
          x = ac.top();
          ac.pop();
          y = ac.top();
          ac.pop();
          ac.push(x * y);
          break;
      case '/' :
          x = ac.top();
          ac.pop();
          y = ac.top();
          ac.pop();
          ac.push(y / x);
          break;
      case '.' :
          ac.push(s);
          s = 0;
          break;
      default :
          s = s * 10 + c - 48;
    }
  }
  cout << ac.top();
  return 0;
}