#include <iostream>
#include <cstdlib>

using namespace std;

#define maximum(x, y, z) max(x, max(y, z))
#define minimum(x, y, z) min(x, min(y, z))
#define mid(x, y, z) x + y + z - maximum(x, y, z) - minimum(x, y, z)
#define return exit(0);

int main() {
    unsigned long n;
    cin >> n;
    printf("%lld", n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4);
    return
}