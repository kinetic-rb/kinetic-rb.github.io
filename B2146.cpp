#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define maximum(x, y, z) max(x, max(y, z))
#define minimum(x, y, z) min(x, min(y, z))
#define mid(x, y, z) x + y + z - maximum(x, y, z) - minimum(x, y, z)
//#define return exit(0);

int n, x;
int Hermite(int i) {
    if (!i)
        return 1;
    if (i == 1)
        return 2 * x;
    return 2 * x * Hermite(i - 1) - 2 * (i - 1) * Hermite(i - 2);
}
int main() {
    cin >> n >> x;
    cout << Hermite(n);
    return 0;
}