#include <iostream>
#include <algorithm>

using namespace std;

int tree[500010], rankx[500010];
int n;
long long ans;

struct point {
    int num, val;
} a[500010];

inline void insert(int p, int d) {
    for (; p <= n; p += p & -p)
        tree[p] += d;
}

inline int query(int p) {
    int sum = 0;
    for (; p; p -= p & -p)
        sum += tree[p];
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].val, a[i].num = i;
    stable_sort(a + 1, a + 1 + n, [](const point& q, const point& w) {
        if (q.val == w.val)
            return q.num < w.num;
        return q.val < w.val;
    });
    for (int i = 1; i <= n; i++)
        rankx[a[i].num] = i;
    for (int i = 1; i <= n; i++) {
        insert(rankx[i], 1);
        ans += i - query(rankx[i]);
    }
    cout << ans;
    return 0;
}