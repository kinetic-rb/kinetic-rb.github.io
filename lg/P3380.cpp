#include<cstdio>
#include<algorithm>
#include<vector>
#define il inline
#define rg register
#define vd void
#define sta static
using std::vector;
typedef long long ll;
il int gi() {
    rg int x = 0, f = 1;
    rg char ch = getchar();
    while (ch < '0' || ch > '9')f = ch == '-' ? -1 : f, ch = getchar();
    while (ch >= '0' && ch <= '9')x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
const int maxn=50001;
int lb[maxn],W[maxn],n,N=65536,m;
typedef const int& fast;
vector<int>d[65537<<1];
vector<int>::iterator it;
il vd Insert(fast x,fast y){d[x].insert(upper_bound(d[x].begin(),d[x].end(),y),y);}
il vd Erase(fast x,fast y){d[x].erase(lower_bound(d[x].begin(),d[x].end(),y));}
il int Rank(fast x,fast y){return lower_bound(d[x].begin(),d[x].end(),y)-d[x].begin();}
il int Kth(fast x,fast y){return d[x][y-1];}
il int Prev(fast x,fast y) {
    it = lower_bound(d[x].begin(), d[x].end(), y);
    if (it == d[x].begin())return -2147483647;
    return *--it;
}
il int Next(fast x,fast y) {
    it = upper_bound(d[x].begin(), d[x].end(), y);
    if (it == d[x].end())return 2147483647;
    return *it;
}
il vd UPD1(rg int x,fast y){for(x+=N;x;x>>=1)Insert(x,y);}
il vd UPD2(rg int x,fast y){for(x+=N;x;x>>=1)Erase(x,y);}
il int max(fast a,fast b){return a>b?a:b;}
il int min(fast a,fast b){return a<b?a:b;}
il int RNK(rg int l,rg int r,fast k) {
    sta int ret;
    ret = 1;
    for (l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
        if (~l & 1)ret += Rank(l ^ 1, k);
        if (r & 1)ret += Rank(r ^ 1, k);
    }
    return ret;
}
il int PRE(rg int l,rg int r,fast k) {
    sta int ret;
    ret = -2147483647;
    for (l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
        if (~l & 1)ret = max(ret, Prev(l ^ 1, k));
        if (r & 1)ret = max(ret, Prev(r ^ 1, k));
    }
    return ret;
}
il int NXT(rg int l,rg int r,fast k) {
    sta int ret;
    ret = 2147483647;
    for (l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
        if (~l & 1)ret = min(ret, Next(l ^ 1, k));
        if (r & 1)ret = min(ret, Next(r ^ 1, k));
    }
    return ret;
}
int main() {
    n = gi(), m = gi();
    for (N = 1; N < n; N <<= 1)
        for (rg int i = 1; i <= n; ++i)lb[i] = i & -i;
    for (rg int i = 1; i <= n; ++i) {
        W[i] = gi();
        UPD1(i, W[i]);
    }
    int opt, l, r, k;
    
    while (m--) {
        opt = gi();
        if (opt == 3)l = gi(), k = gi();
        else l = gi(), r = gi(), k = gi();
        if (opt == 1)printf("%d
", RNK(l, r, k));
        else if (opt == 2) {
            sta int ll, rr, mid;
            ll = 0, rr = 100000000;
            while (ll < rr) {
                mid = ((ll + rr) >> 1) + 1;
                if (RNK(l, r, mid) > k)rr = mid - 1;
                else ll = mid;
            }
            printf("%d
", ll);
        } else if (opt == 3) {
            UPD2(l, W[l]);
            UPD1(l, W[l] = k);
        } else if (opt == 4)
            printf("%d
", PRE(l, r, k));
        else if (opt == 5)
            printf("%d
", NXT(l, r, k));
    }
    return 0;
}