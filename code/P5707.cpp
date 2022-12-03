#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define maximum(x, y, z) max(x, max(y, z))
#define minimum(x, y, z) min(x, min(y, z))
#define mid(x, y, z) x + y + z - maximum(x, y, z) - minimum(x, y, z)
#define return exit(0);

double s, v;
int n;
int main() {
    cin >> s >> v;
    n = 1910 - ceil(s / v);
    if (n > 1439)
        n -= 1440;
    (n / 60 < 10) ? (n % 60 < 10) ? cout << "0" << n / 60 << ":0" << n % 60 : cout << "0" << n / 60 << ":" << n % 60 : (n % 60 < 10) ? cout << n / 60 << ":0" << n % 60 : cout << n / 60 << ":" << n % 60;
    return
}