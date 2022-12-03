#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 3, M = 1e3 + 3;
constexpr ll mod = 1e9 + 7; 

namespace IO {
    constexpr int SIZE = (1 << 20) | 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE],*oS = obuf, *oT = obuf + SIZE - 1;
    char _st[55];
    int _qr = 0;
    inline char gc() {
        return (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++) : *iS++);
    }
    inline void qread() {}
    template<class T1, class ...T2>
    inline void qread(T1 &IEE, T2&... ls) {
        register T1 __ = 0, ___ = 1;
        register char ch;
        while(!isdigit(ch = gc())) ___ = (ch == '-') ? -___ : ___;
        do {
            __ = (__ * 10) + (ch & 15);
        }while(isdigit(ch = gc()));
        __ *= ___;
        IEE = __;
        qread(ls...);
        return ;
    }
    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return ;
    }
    inline void putc_(char _x) {
        *oS++ = _x;
        if(oS == oT) flush();
    }
    inline void qwrite() {}
    template<class T1, class ...T2>
    inline void qwrite(T1 IEE, T2... ls) {
        if(!IEE) putc_('0');
        if(IEE < 0) putc_('-'), IEE = -IEE;
        while(IEE) _st[++_qr] = IEE % 10 ^ 48, IEE /= 10;
        while(_qr) putc_(_st[_qr--]);
        putc_('\n');
        qwrite(ls...);
        return ;
    }
    struct Flusher_{~Flusher_(){flush();}}io_flusher;
}

using namespace IO;

int n, m;
int L[M], R[M];
int len, s;
ll a[N], sum[M], pre[M][M];

int bl (int x) {
\treturn (x - 1) / len + 1;
}

int main () {
    qread(n, m);
    len = 255;
    s = (n - 1) / len + 1;
    for (int i = 1; i <= n; ++i) {
        qread(a[i]);
    }
    for (int i = 1; i <= s; ++i) {
        L[i] = R[i - 1] + 1;
        R[i] = i * len;
    }
    R[s] = n;
    for (int i = 1; i <= s; ++i) {
        for (int j = L[i]; j <= R[i]; ++j) {
            sum[i] += a[j];
        }
    }
    while (m--) {
        int op, x, y, z;
        qread(op, x, y);
        if (op == 1) {
            qread(z);
            if (x >= 100) {
                for (; y <= n; y += x) {
                    a[y] += z;
                    sum[bl(y)] += z;
                }
            }
            else {
                for (int i = y % x; i < x; ++i) {
                    pre[x][i] += z;
                }
            }
        }
        if (op == 2) {
            int xb = bl(x), yb = bl(y);
            ll res = 0;
            if (xb == yb) {
                for (int i = x; i <= y; ++i) {
                    res += a[i];
                }
            }
            else {
                for (int i = x; i <= R[xb]; ++i) {
                    res += a[i];
                }
                for (int i = xb + 1; i <= yb - 1; ++i) {
                    res += sum[i];
                }
                for (int i = L[yb]; i <= y; ++i) {
                    res += a[i];
                }
            }
            for (int i = 1; i < 100; ++i) {
                int lg = x / i, rg = y / i;
                if (lg == rg) {
                    res += pre[i][y % i] - pre[i][x % i - 1];
                }
                else {
                    res += pre[i][i - 1] * (rg - lg - 1);
                    res += pre[i][i - 1] - pre[i][x % i - 1];
                    res += pre[i][y % i];
                }
            }
            qwrite((res + mod * mod) % mod);
        }
    }
    return 0;
}
