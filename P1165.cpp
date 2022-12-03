#include <iostream>
#include <stack>

using namespace std;

stack <int> st;

int main() {
\tint n;
\tfor (cin >> n; n--;) {
\t\tint k, x;
\t\tcin >> k;
\t\tswitch (k) {
\t\t\tcase 0 :
\t\t\t\t\tcin >> x;
\t\t\t\t\tst.push(st.empty() ? x : max(x, st.top()));
\t\t\t\t\tbreak;
\t\t\tcase 1 :
\t\t\t\t\tif (!st.empty())
\t\t\t\t\t\tst.pop();
\t\t\t\t\tbreak;
\t\t\tdefault :
\t\t\t\t\tcout << (st.empty() ? 0 : st.top()) << '\n';
\t\t}
\t}
\treturn 0;
}