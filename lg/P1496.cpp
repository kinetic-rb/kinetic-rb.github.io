#include <iostream>
#include <algorithm>

using namespace std;

int n, * a = new int [21000], * b = new int [21000], d[410000] = {-0x7fffffff}, dtp, ctp, * ans = new int [810000];

int bnrsch(int x) {
    int l = 1, r = ctp, md;
    while (l + 1 < r) {
        md = (l + r) >> 1;
        (d[md] <= x ? l : r) = md;
    }
    return d[l] == x ? l : r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        d[++dtp] = a[i];
        d[++dtp] = b[i];
    }
    sort(d + 1, d + dtp + 1);
    ctp = unique(d + 1, d + dtp + 1) - d - 1;
    for (int i = 1; i <= n; ++i) {
        a[i] = bnrsch(a[i]);
        b[i] = bnrsch(b[i]);
        for (int j = a[i]; j < b[i]; ++j)
            ans[j] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= ctp; ++i)
        if (ans[i])
            cnt += d[i + 1] - d[i];
    cout << cnt;
    return 0;
}