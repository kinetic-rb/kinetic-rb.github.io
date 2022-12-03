#include <iostream>
#include <stack>
#include <string>

using namespace std;

inline bool check(string s) {
\tstack<char> p;
\tp.push('#');
\tfor (int i = 0; i < s.size(); i++) {
\t\tchar c = s[i];
\t\tif (c == ')') {
\t\t\tif (p.top() != '(')
\t\t\t\treturn false;
\t\t\tp.pop();
\t\t} else if (c == ']') {
\t\t\tif (p.top() != '[')
\t\t\t\treturn false;
\t\t\tp.pop();
\t\t} else {
\t\t\tp.push(c);
\t\t}
\t}
\treturn (p.size() == 1);
}

int main() {
\tint T;
\tcin >> T;
\tfor (getchar(); T--; ) {
\t\tstring str, s;
\t\tgetline(cin, str);
\t\tfor (int i = 0; i < str.size(); i++) {
\t\t\tif (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
\t\t\t\ts.push_back(str[i]);
\t\t}
\t\t(check(s)) ? cout << "Yes
" : cout << "No
";
\t}
\treturn 0;
}