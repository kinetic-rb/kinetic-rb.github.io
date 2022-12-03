#include <iostream>
#include <cmath>
#define int long

using namespace std;

int f[200];

inline int fx(int n) {
    if (f[n])
      return f[n];
    return f[n] = fx(n - 1) + fx(n - 2);
}

signed main() {
    *f = f[1] = 1;
    int x, i;
    cin >> x;
    fx(64);
    for (i = 0; fx(i) + fx(i + 1) < x; i++);
    printf("m=%d
n=%d", fx(i), fx(i + 1));
    return 0;
}