#include <iostream>
#include <algorithm>

using namespace std;

struct AC {
\tint x, y;
} ap[5005];

int main() {
\tint n, s, h, b, ans = 0;
\tcin >> n >> s >> h >> b;
\th += b;
\tfor (int i = 0; i < n; i++)
\t\tcin >> ap[i].x >> ap[i].y;
\tstable_sort(ap, ap + n, [](const AC& x, const AC& y) {
\t\treturn x.y < y.y;
\t});
\tfor (int i = 0; i < n; i++) {
\t\tif (ap[i].x <= h)
\t\t\tif (ap[i].y <= s) {
\t\t\t\tans++;
\t\t\t\ts -= ap[i].y;
\t\t\t}
\t\tif (!s)
\t\t\tbreak;
\t}
\tcout << ans;
\treturn 0;
}