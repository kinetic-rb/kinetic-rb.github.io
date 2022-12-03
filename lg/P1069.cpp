#include <bits/stdc++.h>

using namespace std;

int read() {
    char ch = getchar();
    int a = 0, x = 1;
    for(; ch < '0' || ch > '9'; ch = getchar())
        if(ch == '-')
            x = -x;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        a = (a << 3) + (a << 1) + (ch - '0');
    return a * x;
}
int gcd(int a,int b) {
    return (!b) ? a : gcd(b, a % b);
}
int main() {
    int n, m1, m2, minx = INT_MAX, gcdd, m, s, q, t, flag, tot, ans, tots, totq, S[10001];
    memset(S, 0, sizeof(S));
    n = read();
    m1 = read();
    m2 = read();
    if(m1 == 1) {
        printf("0");
        return 0;
    }
    for(int i = 1; i <= n; i++)
        S[i] = read();
    for(int i = 1; i <= n; i++) {
        m = m1;
        s = S[i];
        flag = 1;
        for(t = tot = 0; m != 1; t++) {
            gcdd = gcd(m, s);
            if(gcdd == 1) {
                flag = 0;
                break;
            }
            m /= gcdd;
            q = s / gcdd;
            s = gcdd;
        }
        if(flag) {
            int gc = gcd(q, s);
            if(gc != 1 && gc != s) {
                for(totq = tots = 0; !(q % gc); q /= gc)
                    totq++;
                for(; !(s % gc); s /= gc)
                    tots++;
                (!((t * m2 * tots + totq * (t - 1) * m2) % (tots + totq))) ? ans = (t * m2 * tots + totq * (t - 1) * m2) / (tots + totq) : ans = (t * m2 * tots + totq * (t - 1) * m2) / (tots + totq) + 1;
                minx = min(minx, ans);
            } else {
                for(; !(q % s); q /= s)
                    tot++;
                (!((t * m2 + tot * (t - 1) * m2) % (tot + 1))) ? ans = (t * m2 + tot * (t - 1) * m2) / (tot + 1)
                                                               : ans = (t * m2 + tot * (t - 1) * m2) / (tot + 1) + 1;
                minx = min(minx, ans);
            }
        }
    }
    (minx == INT_MAX) ? cout << -1 : cout << minx;
    return 0;
}