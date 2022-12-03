#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct AC{
\tdouble x, y, z;
\tbool operator < (const AC & i) const {
\t\treturn z < i.z;
\t}
}ac[50050];

int main() {
    register_t n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ac[i].x >> ac[i].y >> ac[i].z;
    }
    sort(ac, ac + n);
    double sum = 0, lx = ac[0].x, ly = ac[0].y, lz = ac[0].z;
    for (int i = 1; i < n; i++) {
        sum += sqrt(abs(lx - ac[i].x) * abs(lx - ac[i].x) + abs(ly - ac[i].y) * abs(ly - ac[i].y) + abs(lz - ac[i].z) * abs(lz - ac[i].z));
        lx = ac[i].x;
        ly = ac[i].y;
        lz = ac[i].z;
    }
    cout << fixed << setprecision(3) << sum;
    return 0;
}