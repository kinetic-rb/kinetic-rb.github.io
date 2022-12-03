#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct it{
\tint a, b, c;\t//n, w, v;
\tit(){}
\tit(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};
map<string, it>mp;
int m, n, dp[100];
int main() {
\tcin >> m >> n;
\tm = 21 - m;\t// V 
\tint a, b, c;
\tstring s;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> a >> b >> c >> s;
\t\tif (mp.count(s) == 0) {\t//\u4e0d\u5b58\u5728 
\t\t\tmp.insert(pair<string, it>(s, it(a, b, c)));
\t\t} else {
\t\t\tmp[s].a += a;
\t\t}
\t}
\tif (m == 0) {
\t\tcout << 0 << endl;
\t} else {
\t\tfor (auto iter = mp.begin(); iter != mp.end(); iter++) {
\t\t\tit temp = iter->second;
\t\t\tfor (int j = m; j > 0; j--) {
\t\t\t\tfor (int k = 0; k <= temp.a; k++) {
\t\t\t\t\tif (k <= temp.c) {
\t\t\t\t\t\tdp[j] = max(dp[j - 1] + k * temp.b, dp[j]);
\t\t\t\t\t}
\t\t\t\t}
\t\t\t}
\t\t}
\t\tcout << dp[m] << endl;
\t}
\treturn 0;
} 