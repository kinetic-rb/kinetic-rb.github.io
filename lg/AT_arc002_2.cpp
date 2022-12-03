#include <iostream>

using namespace std;

int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(false);
    int y, m, d, t;
    char ch;
\tcin >> y >> ch >> m >> ch >> d;
\ta[2] += (!(y % 4) && y % 100 || !(y % 400));
\twhile (y % (d * m)) {
\t\tif (++d > a[m]) {
\t\t\tm++;
\t\t\td = 1;
\t\t}
\t\tif (m > 12)\t{
\t\t\ty++;
\t\t\tm = 1;
\t\t}\t
    }
    cout << y << '/' << m / 10 << m % 10 << '/' << d / 10 << d % 10 << endl;
\treturn 0;
}
