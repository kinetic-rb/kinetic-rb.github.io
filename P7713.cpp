#include <bits/stdc++.h>

#define LL long long
#define R register

using namespace std;

LL n, m, rem, sum, a[100009];

inline LL read(){
    LL R s = 0,w = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-') w = -1; ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        s = (s << 1) + (s << 3) + (ch ^ 48);
        ch = getchar();
    }
    return s * w;
}

int main() {
    n = read(), m = read(), sum = m;
    for (LL R i = 1; i <= n; i += 1)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for (LL R i = 2; i < n; i += 1) {
        rem += a[n] - a[i];
        sum += a[i];
    }
    if (m > rem)
        sum -= (m - rem - 1) / (n - 1) + 1;
    cout << sum;
    return 0;
}