#include <iostream>
#include <array>

using namespace std;

long long N, fac, ans;
array <long long, 12> a, c;
char * p;

inline void read(register long long & x) {
    while(!isdigit(*p))
        p++;
    while(isdigit(* p))
        x = x * 10 + (* p & 15), ++p;
}

int main() {
    scanf("%lld", &N);
    fac = 1;
    p = new char[11];
    fread(p, 1, N * 8 + 100, stdin);
    for (register long long i = N; i; --i)
        read(a[i]);
    for (register long long i = 1, s, j; i <= N; ++i) {
        for (s = 0, j = a[i]; j; j -= j & -j)
            s += c[j];
        ans = (ans + 1 * fac * s) % 998244353;
        fac = fac * i % 998244353;
        for (j = a[i]; j <= N; j += j & -j)
            c[j]++;
    }
    printf("%lld
", ans + 1);
    return 0;
}