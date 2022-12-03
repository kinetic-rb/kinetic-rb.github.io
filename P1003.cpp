#include <iostream>
#include <array>

using namespace std;

array<int, 10001> sx, sy, ex, ey, id;

int main() {
\tint n, x, y, cnt = 0;
\tcin >> n;
\tfor (int i = 0; i < n; i++) {
\t\tcin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
\t}
\tcin >> x >> y;
\tfor (int i = n - 1; i > -1; i--) {
\t\tif (x >= sx[i] && x <= sx[i] + ex[i] && y >= sy[i] && y <= sy[i] + ey[i]) {
\t\t    cout << ++i;
\t\t    return 0;
\t\t}
\t}
\tcout << -1;
\treturn 0;
}