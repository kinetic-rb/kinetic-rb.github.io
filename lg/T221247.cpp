#include <iostream>
#include <ctime>
#define int long

using namespace std;

int p[10000], a[10000];
int cnt;

inline void fact(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            p[cnt] = i;
            while (!(n % i)) {
                n /= i;
                a[cnt]++;
            }
            cnt++;
        }
    }
    if (n > 1) {
        p[cnt] = n;
        a[cnt] = 1;
        cnt++;
    }
}

signed main() {
    int n;
    cin >> n;
    fact(n);
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
        cout << p[i] << ' ' << a[i] << '\n';
    }
    return 0;
}