#include <iostream>
#include <algorithm>
#define int long

using namespace std;

int x[305];

signed main() {
    int n, head = 0, sum = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    stable_sort(x, x + n + 1);
    for (reverse(x, x + n + 1); head < n; cnt++ & 1 ? head++ : n--)
        sum += (x[head] - x[n]) * (x[head] - x[n]);
    cout << sum;
    return 0;
}