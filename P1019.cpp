#include <iostream>

using namespace std;

string str[20];
char use[20];
int length, n;

inline static int match(string str1, string str2) {
\tfor (int i = 1; i < min(str1.size(), str2.size()); i++) {
\t\tbool flag = true;
\t\tfor (int j = 0; j < i; j++)
\t\t\tif (str1[str1.size() - i + j] != str2[j])
\t\t\t\tflag = false;
\t\tif (flag)
\t\t\treturn i;
\t}
\treturn 0;
}

inline void solve(string strnow, int lengthnow) {
\tlength = max(lengthnow, length);
\tfor (int i = 0; i < n; i++) {
\t\tif (use[i] > 1)
\t\t\tcontinue;
\t\tif (match(strnow, str[i])) {
\t\t\tuse[i]++;
\t\t\tsolve(str[i], lengthnow + str[i].size() - match(strnow, str[i]));
\t\t\tuse[i]--;
\t\t}
\t}
}
int main() {
\tcin >> n;
\tfor (int i = 0; i <= n; i++)
\t\tcin >> str[i];
\tsolve(' ' + str[n], 1);
\tcout << length;
\treturn 0;
}