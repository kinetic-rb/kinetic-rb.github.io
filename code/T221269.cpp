#include <iostream>
#include <algorithm>

using namespace std;

struct AC {
    int p, v;
    inline bool operator < (const AC& comp) const {
        return p < comp.p;
    }
} cst[200005];

int ac[100005];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        cst[i] = {l, 1};
        cst[i + n] = {r + 1, -1};
    }
    stable_sort(cst + 1, cst + 1 + 2 * n);
    for (int i = 1, j = 1, s = 0; i <= 2 * n; i = j) {
        for (ac[s] += cst[i].p - cst[i - 1].p; j <= 2 * n && cst[j].p == cst[i].p; j++)
            s += cst[j].v;
    }
    for (int i = 1; i <= n; i++)
        cout << ac[i] << ' ';
    return 0;
}