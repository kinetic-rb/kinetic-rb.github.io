#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, x, an, e, t = 1;
    cin >> n >> a >> b >> x;
    e = n;
    for (int i = 0; i < b; i++)
        t *= a;
    n /= t;
    an = x - n % a;
    an *= t;
    e += an;
    cout << e;
    return 0;
}