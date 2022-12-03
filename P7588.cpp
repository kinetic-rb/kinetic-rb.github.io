#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri register int
#define ll long long
#define ui unsigned int
il ll read() {
    bool f = true;
    ll x = 0;
    register char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = 0;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    if (f) return x;
    return ~(--x);
}
il void write(const ll &x){if(x>9) write(x/10);putchar(x%10+'0');}
il void print(const ll &x) {x<0?putchar('-'),write(~(x-1)):write(x);putchar('\n');}
il ll max(const ll &a,const ll &b){return a>b?a:b;}
il ll min(const ll &a,const ll &b){return a<b?a:b;}
const int MAXN=1e8+7,MAXM=6e6+7;
int prim[MAXM];
bitset<MAXN> flag;
void getphi(int N=1e8) {
    flag[1] = 1;
    for (ri i = 2; i <= N; ++i) {
        if (!flag[i]) prim[++prim[0]] = i;
        for (ri j = 1; j <= prim[0] && prim[j] * i <= N; ++j) {
            flag[i * prim[j]] = 1;
            if (!(i % prim[j])) break;
        }
    }
}
int check(int x) {
    int res = 0;
    for (; x; x /= 10)
        res += x % 10;
    return !flag[res];
}
vector<int> vec;
int top;
inline void init() {
    for (ri i = 1; i <= prim[0]; ++i) {
        int v = prim[i];
        if (check(v))
            vec.push_back(v);
    }
    vec.push_back(1e9);
}
inline int query(int u){
    return upper_bound(vec.begin(),vec.end(),u)-vec.begin()-1;
}
struct Q {
    int l, r;
} q[128];

int main() {
    int t = read(), mx = 0;
    for (ri i = 1; i <= t; ++i) {
        q[i].l = read(), q[i].r = read();
        mx = max(mx, q[i].r);
    }
    getphi(mx);
    init();
    for (ri i = 1; i <= t; ++i) {
        print(query(q[i].r) - query(q[i].l - 1));
    }
    return 0;
}