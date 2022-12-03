#include <bits/stdc++.h>
#define mod 65521
using namespace std;
long long read();
int M(int x) { return x >= mod ? x - mod : x; }
void Add(int& x, int y) { (x += y) >= mod ? x -= mod : x; }
int fsp(unsigned bs, int p) {
    int rt = 1;
    while (p) {
        if (p & 1) rt = bs * rt % mod;
        bs = bs * bs % mod, p >>= 1;
    }
    return rt;
}

long long n;
int k, lim;

int b[102][102];
void work1() {
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= min(i + k, (int)n); ++j)
            ++b[i][i], ++b[j][j], b[i][j] = b[j][i] = mod - 1;
    lim = n - 1;
}

int K;
struct Mat {
    int a[21][21];
    int* operator[](int p) { return a[p]; }
    Mat operator*(Mat& b) {
        static Mat rt;
        for (int i = 1; i <= K; ++i)
            for (int j = 1; j <= K; ++j) {
                rt[i][j] = 0;
                for (int k = 1; k <= K; ++k)
                    Add(rt[i][j], 1ll * a[i][k] * b[k][j] % mod);
            }
        return rt;
    }
} bs, res;

int c[21];

void work2() {
    K = k << 1;
    for (int i = 1; i <= K; ++i)
        bs[i][1] = mod - 1, bs[i][i + 1] = res[i][i] = 1;
    bs[k][1] = K;
    for (long long p = n - K - 1; p; p >>= 1)
        (p & 1) ? res = res * bs : res, bs = bs * bs;

    for (int i = 1; i <= k; ++i) {
        memset(c, 0, sizeof c);
        for (int j = 1; j <= i + k; ++j) c[j] = mod - 1;
        c[i] = k + i - 1;
        for (int j = 1; j <= K; ++j)
            for (int k = 1; k <= K; ++k)
                Add(b[i][j], 1ll * res[j][k] * c[k] % mod);
    }

    for (int i = k + 1; i <= K; ++i) {
        for (int j = i - k; j <= K; ++j) b[i][j] = mod - 1;
        b[i][i] = 3 * k - i + 1;
    }

    lim = K;
    if (1ll * (n - K - 1) * (k + 1) & 1)
        for (int i = 1; i <= K; ++i) b[1][i] = mod - b[1][i];
}

void solve() {
    int res = 1, ny;
    for (int i = 1; i <= lim; ++i) {
        if (!b[i][i])
            for (int j = i; j <= lim; ++j)
                if (b[j][i]) {
                    swap(b[i], b[j]), res = mod - res;
                    break;
                }
        res = 1ll * res * b[i][i] % mod, ny = fsp(b[i][i], mod - 2);
        for (int j = i; j <= lim; ++j) b[i][j] = 1ll * b[i][j] * ny % mod;
        for (int j = i + 1; j <= lim; ++j)
            for (int k = lim; k >= i; --k)
                Add(b[j][k], mod - 1ll * b[j][i] * b[i][k] % mod);
    }
    printf("%d
", M(res));
}
int main() {
    k = read(), (n = read()) <= 20 ? work1() : work2(), solve();
    return 0;
}

long long read() {
    long long x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x;
}