#include<bits/stdc++.h>
using namespace std;
int n, x, y, a, b, c[1005], sum = 0, ans = 0;
int main(){
\tcin >> n >> x >> y >> a >> b;
\tfor (int i = 1; i <= n; i++) {
\t\tcin >> c[i];
\t\tsum += c[i];
\t}
\tsort(c + 1, c + n + 1);
\tfor (ans = 1; ans * a < sum && ans <= x; ans++) {
\t}
\tfor (int i = 1; i * b + ans * a < sum && i <= y; i++, ans++) {
\t}
\tif (x * a + y * b < sum) {
\t\tint i, t = 0;
\t\tfor (i = 1; t + c[i] <= x * a + y * b; i++) {
\t\t\tt += c[i];
\t\t}
\t\tcout << "Error" << endl << i - 1;
\t} else {
\t\tcout << ans;
\t}
\treturn 0;
}

