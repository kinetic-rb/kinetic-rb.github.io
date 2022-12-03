#include <iostream>
#include <vector>

using namespace std;

struct CE {
    int l, c;
} MAX;

inline void Up(CE& f, CE _f) {
    if (_f.l > f.l)
        f = _f;
    else
        if (_f.l == f.l)
            f.c = (f.c + _f.c) % 1000000007;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> num(n);
    vector<CE> f(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++) {
        f[i] = {1, 1};
        for (int j = 0; j < i; j++) {
            if(num[i] >= num[j]) {
                Up(f[i], {f[j].l + 1, f[j].c});
            }
        }
        Up(MAX, f[i]);
    }
    cout << MAX.l << ' ' << MAX.c;
    return 0;
}