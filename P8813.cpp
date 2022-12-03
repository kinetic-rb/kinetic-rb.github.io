#include <iostream>
#define ra __Read_int()

using namespace std;
using tp = long long;

tp __Read_int() {
\ttp x;
\tscanf("%lld", &x);
\treturn x;
}

constexpr tp c_Limit = 1000000000;

signed main() {
\ttp a = ra, b = ra, tar = 1;
\twhile (b) {
\t\tif (b & 1) {
\t\t\tif (tar * a > c_Limit) {
\t\t\t\tputs("-1");
\t\t\t\treturn 0;
\t\t\t}
\t\t\ttar *= a;
\t\t}
\t\ta *= a;
\t\tb >>= 1;
\t\tif (a > c_Limit && b) {
\t\t\tputs("-1");
\t\t\treturn 0;
\t\t}
\t}
\tprintf("%lld
", tar);
\treturn 0;
}