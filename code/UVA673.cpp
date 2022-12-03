#include <iostream>
#include <stack>
#include <string>

using namespace std;

inline bool check(string s) {
  stack<char> p;
  p.push('#');
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == ')') {
      if (p.top() != '(')
        return false;
      p.pop();
    } else if (c == ']') {
      if (p.top() != '[')
        return false;
      p.pop();
    } else {
      p.push(c);
    }
  }
  return (p.size() == 1);
}

int main() {
  int T;
  cin >> T;
  for (getchar(); T--; ) {
    string str, s;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
        s.push_back(str[i]);
    }
    (check(s)) ? cout << "Yes
" : cout << "No
";
  }
  return 0;
}