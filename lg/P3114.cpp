#include <bits/stdc++.h>

using namespace std;

int n, len, ans;
int c[100005], t[200005];

struct L {
    int l, r, x, w; 
} a[50005];

unordered_map<int, int> p;
unordered_map<int, bool> f;

bool cmp (L q, L p) {
    return q.x < p.x;
}

void insert (int x) {
    if (f[x] == 0) {
        f[x] = 1;
        len++;
        c[len] = x;
    }
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].x >> a[i].w;
        a[i].r = a[i].l + 1;
        a[i].l = -(a[i].l + 1) * a[i].w;
        a[i].r = -(a[i].r - 1) * a[i].w;
        insert(a[i].l);
        insert(a[i].r);
    }
    sort(a + 1, a + n + 1, cmp);
    sort(c + 1, c + len + 1);
    for (int i = 1; i <= len; i++) {
        p[c[i]] = i * 2;
    }
    for (int i = 1; i <= n; i++) {
        bool fl = 0;
        for (int j = p[a[i].l]; j <= p[a[i].r]; j++) {
            if (t[j] == 0) {
                fl = 1;
                t[j] = 1;
            }
        }
        ans += fl;
    }
    cout << ans;
    return 0;
}