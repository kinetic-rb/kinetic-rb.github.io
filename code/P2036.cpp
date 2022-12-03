#include <iostream>
#include <cmath>

using namespace std;

int n, cr, cv, MIN = 0x7fffffff;
int rage[1000000], vrage[1000000], jr[1000000], jv[1000000];

inline void solve1(int x, int sum) {
    if (x == n) {
        jr[cr++] = sum;
        return;
    }
    solve1(x + 1, sum);
    solve1(x + 1, sum + vrage[x]);
}

inline void solve2(int x, int sum) {
    if (x == n) {
        jv[cv++] = sum;
        return;
    }
    solve2(x + 1, sum);
    solve2(x + 1, sum * rage[x]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> rage[i] >> vrage[i];
    }
    solve1(0, 0);
    solve2(0, 1);
    for (int i = 1; i < int(pow(2, n)); i++)
        MIN = min(MIN, abs(jr[i] - jv[i]));
    cout << max(MIN, 0);
    return 0;
}