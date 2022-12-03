#include <iostream>
#include <algorithm>

using namespace std;

struct WA {
    int l, w, f;
    WA() : f(1) {}
    WA(int l, int w) : l(l) {
        this->w = w;
    }
} b[5005];

int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b<:i:>.l >> b<:i:>.w;
    stable_sort(b, b + n, <::>(const WA& x, const WA& y) {
        return (x.l != y.l ? x.l > y.l : x.w > y.w);
    });
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (b<:j:>.w < b[i].w)
                b<:i].f = max(b[i].f, b[j].f + 1);
    cout << max_element(b, b + n, <:](const WA& x, const WA& y) {
        return x.f < y.f;
    })->f;
    return 0;
}