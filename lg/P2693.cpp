#include <iostream>
#include <set>
#include <array>
#define int long

using namespace std;

set<array<int, 3>> all;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, y, z, a, b, c;
    cin >> n >> x >> y >> z >> a >> b >> c;
    if (n < 5) {
        cout << n * n * n;
        return 0;
    }
    for (register int i = (x - 2 + n) % n; i != (x + 3) % n; i++)
        for (register int j = (y - 2 + n) % n; j != (y + 3) % n; j++)
            for (register int k = (z - 2 + n) % n; k != (z + 3) % n; k++) {
                array<int, 3> temp;
                i %= n;
                j %= n;
                k %= n;
                temp[0] = i;
                temp[1] = j;
                temp[2] = k;
                all.insert(temp);
            }
    for (register int i = (a - 2 + n) % n; i != (a + 3) % n; i++)
        for (register int j = (b - 2 + n) % n; j != (b + 3) % n; j++)
            for (register int k = (c - 2 + n) % n; k != (c + 3) % n; k++) {
                array<int, 3> temp;
                i %= n;
                j %= n;
                k %= n;
                temp[0] = i;
                temp[1] = j;
                temp[2] = k;
                all.insert(temp);
            }
    cout << all.size();
    return 0;
}