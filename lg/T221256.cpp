#include <iostream>
#include <cstring>

using namespace std;

int p[10000], a[10000];
int cnt;

inline void fact(int &n) {
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

int main() {
    int t;
    for (cin >> t; t--; cnt = 0) {
        int n, sum = 1;
        cin >> n;
        fact(n);
        for (int i = 0; i < cnt; i++) {
            sum *= a[i] + 1;
        }
        cout << sum << '\n';
        memset(a, 0, sizeof a);
    }
    return 0;
}