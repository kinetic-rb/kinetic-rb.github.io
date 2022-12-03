#include <iostream>
#include <stack>

using namespace std;

int main() {
\tstack<int> ac;
\tchar c = '#';
\tint s = 0, x, y;
\twhile (c != '@') {
\t\tcin >> c;
\t\tswitch (c) {
\t\t\tcase '+' :
\t\t\t\t\tx = ac.top();
\t\t\t\t\tac.pop();
\t\t\t\t\ty = ac.top();
\t\t\t\t\tac.pop();
\t\t\t\t\tac.push(x + y);
\t\t\t\t\tbreak;
\t\t\tcase '-' :
\t\t\t\t\tx = ac.top();
\t\t\t\t\tac.pop();
\t\t\t\t\ty = ac.top();
\t\t\t\t\tac.pop();
\t\t\t\t\tac.push(y - x);
\t\t\t\t\tbreak;
\t\t\tcase '*' :
\t\t\t\t\tx = ac.top();
\t\t\t\t\tac.pop();
\t\t\t\t\ty = ac.top();
\t\t\t\t\tac.pop();
\t\t\t\t\tac.push(x * y);
\t\t\t\t\tbreak;
\t\t\tcase '/' :
\t\t\t\t\tx = ac.top();
\t\t\t\t\tac.pop();
\t\t\t\t\ty = ac.top();
\t\t\t\t\tac.pop();
\t\t\t\t\tac.push(y / x);
\t\t\t\t\tbreak;
\t\t\tcase '.' :
\t\t\t\t\tac.push(s);
\t\t\t\t\ts = 0;
\t\t\t\t\tbreak;
\t\t\tdefault :
\t\t\t\t\ts = s * 10 + c - 48;
\t\t}
\t}
\tcout << ac.top();
\treturn 0;
}