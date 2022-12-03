#include <iostream>
#include <algorithm>

using namespace std;

int a[100010], d1[100010], d2[100010], n;

int main() {
    while (cin >> a[++n]);
    int len1 = 1, len2 = 1;
    d1[1] = d2[1] = a[1];
    for (int i = 2; i < n; i++) {
        if (d1[len1] >= a[i])
            d1[++len1] = a[i];
        else
            *upper_bound(d1 + 1, d1 + 1 + len1, a[i], greater<int>()) = a[i];
        if (d2[len2] < a[i])
            d2[++len2] = a[i];
        else
            *lower_bound(d2 + 1, d2 + 1 + len2, a[i]) = a[i];
    }
    cout << len1 << '\n' << len2;
    return 0;
}