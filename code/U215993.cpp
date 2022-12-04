#include<bits/stdc++.h>
using namespace std;
const int mx_block = 505;
const int mx_n = 200005;
const int mx_p = 10005;
int n, m, p, block, sum;
int opt, l, r, x, lb, rb, ans;
int a[mx_n], pre[mx_block][mx_p], sol[mx_block], L[mx_block], R[mx_block];
int main () {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= p;
    }
    block = sqrt(n);
    sum = n / block + 1;
    if (n % block == 0) {
        sum--;
    }
    for (int i = 1; i <= sum; i++) {
        L[i] = 1 + (i - 1) * block;
        R[i] = i * block;
    }
    R[sum] = n;
    for (int i = 1; i <= sum; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            pre[i][a[j]]++;
        }
    }
    while (m--) {
        cin >> opt >> l >> r;
        lb = (l - 1) / block + 1;
        rb = (r - 1) / block + 1;
        if (opt == 1) {
            cin >> x;
            if (lb == rb) {
                for (int i = l; i <= r; i++) {
                    pre[lb][a[i]]--;
                    a[i] = (a[i] + x) % p;
                    pre[lb][a[i]]++;
                }
                continue;
            }
            if (l == L[lb]) {
                lb--;
            }
            else {
                for (int i = l; i <= R[lb]; i++) {
                    pre[lb][a[i]]--;
                    a[i] = (a[i] + x) % p;
                    pre[lb][a[i]]++;
                }
            }
            if (r == R[lb]) {
                rb++;
            }
            else {
                for (int i = L[rb]; i <= r; i++) {
                    pre[rb][a[i]]--;
                    a[i] = (a[i] + x) % p;
                    pre[rb][a[i]]++;
                }
            }
            for (int i = lb + 1; i <= rb - 1; i++) {
                sol[i] = (sol[i] + p - x) % p;
            }
        }
        if (opt == 2) {
            ans = 0;
            if (lb == rb) {
                for (int i = l; i <= r; i++) {
                    ans += (a[i] % p == sol[lb]);
                }
                cout << ans << endl;
                continue;
            }
            if (l == L[lb]) {
                lb--;
            }
            else {
                for (int i = l; i <= R[lb]; i++) {
                    ans += (a[i] % p == sol[lb]);
                }
            }
            if (r == R[rb]) {
                rb++;
            }
            else {
                for (int i = L[rb]; i <= r; i++) {
                    ans += (a[i] % p == sol[rb]);
                }
            }
            for (int i = lb + 1; i < rb; i++) {
                ans += pre[i][sol[i]];
            }
            cout << ans << endl;
        }
    }
    return 0;
}