#include <iostream>
#include <cstring>
#include <map>

using namespace std;

#define mod 1000000007
int n, ap[50][50], now, vis[50], Hash[2][500005], sta[2][500005], qwq[15], MOD = 499979, num[2];
struct st {
    int a[14];
    st() {
        memset(a, 0, sizeof a);
    }
} fin, sf[2][500005];

struct ro {
    int fi, sc;
    ro(int fi = 0, int sc = 0) : fi(fi), sc(sc) {}
} state[2][500005];

inline ro mix(ro x, ro y) {
    if (x.fi < y.fi) return x;
    else if (x.fi > y.fi) return y;
    else return ro(x.fi, (x.sc + y.sc) % mod);
}

inline void montion(st& x) {
    int s[14], tot = 6;
    memset(s, 0, sizeof(s));
    for (int i = 0; i <= 2 * n; i++) {
        if (x.a[i] > 6 && !s[x.a[i]]) s[x.a[i]] = ++tot;
    }
    for (int i = 0; i <= 2 * n; i++) {
        if (x.a[i] > 6) x.a[i] = s[x.a[i]];
    }
}

inline void hashx(st x, ro nowr) {
    int has = 0;
    for (int i = 0; i <= 2 * n; i++) {
        has = (has + qwq[i] * x.a[i]) % MOD;
    }
    int i = has;
    while (Hash[now][i]) {
        int flag = 0;
        for (int t = 0; t <= 2 * n; t++) {
            if (sf[now][Hash[now][i]].a[t] != x.a[t]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            if (nowr.fi < state[now][Hash[now][i]].fi) {
                state[now][Hash[now][i]] = nowr;
            }
            else if (nowr.fi == state[now][Hash[now][i]].fi) {
                state[now][Hash[now][i]].sc = (nowr.sc + state[now][Hash[now][i]].sc) % mod;
            }
            return;
        }
        i = (i + 1) % mod;
    }
    sta[now][++num[now]] = i;
    Hash[now][i] = num[now];
    state[now][Hash[now][i]] = nowr;
    sf[now][Hash[now][i]] = x;
}

int main() {
    qwq[0] = 1;
    for (int i = 1; i <= 13; i++) {
        qwq[i] = qwq[i - 1] * 8 % MOD;
    }
    while (cin >> n) {
        for (int i = 1; i <= 2 * n; i++) {
            for (int t = 1; t <= 4 * n; t++) {
                ap[i][t] = 7;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int t = n * 2 - i * 2 + 2; t <= 4 * n; t++) {
                cin >> ap[i][t];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= 4 * n - 2 * i + 1; t++) {
                cin >> ap[i + n][t];
            }
        }
        for (int i = 1; i <= 2 * n; i++) {
            for (int t = 1; t <= 4 * n; t++) {
                if (ap[i][t] >= 1 && ap[i][t] <= 6) {
                    if (!vis[ap[i][t]]) {
                        vis[ap[i][t]] = 1;
                        ap[i][t] = ap[i][t] * 2 - 1;
                    } else
                        ap[i][t] = ap[i][t] * 2;
                }
            }
        }
        memset(state, 0, sizeof state);
        memset(sf, 0, sizeof sf);
        memset(Hash, 0, sizeof Hash);
        memset(sta, 0, sizeof sta);
        memset(vis, 0, sizeof vis);
        memset(num, 0, sizeof num);
        hashx(fin, ro(0, 1));
        for (int i = 1; i <= 2 * n; i++) {
            for (int t = 1; t <= 2 * n; t++) {
                now = now ^ 1;
                for (int j = 1; j <= num[now]; j++) {
                    state[now][Hash[now][sta[now][j]]] = ro(0, 0);
                    sf[now][Hash[now][sta[now][j]]] = fin;
                    Hash[now][sta[now][j]] = 0;
                }
                num[now] = 0;
                st nowf, bf;
                ro nowr, br;
                for (int j = 1; j <= num[now ^ 1]; j++) {
                    bf = sf[now ^ 1][Hash[now ^ 1][sta[now ^ 1][j]]], br = state[now ^ 1][Hash[now ^ 1][sta[now ^
                        1][j]]];
                    if (!ap[i][t * 2 - 1]) {
                        if (bf.a[t - 1] && bf.a[t]) {
                            if (bf.a[t - 1] <= 6 && bf.a[t] <= 6) {
                                if ((bf.a[t - 1] + 1) / 2 == (bf.a[t] + 1) / 2) {
                                    nowf = bf, nowr = br, nowr.fi++;
                                    nowf.a[t] = nowf.a[t - 1] = 0;
                                    hashx(nowf, nowr);
                                }
                            } else if (bf.a[t] != bf.a[t - 1]) {
                                nowf = bf, nowr = br, nowr.fi++;
                                int mi = min(nowf.a[t - 1], nowf.a[t]), mx = max(nowf.a[t - 1], nowf.a[t]);
                                for (int j = 0; j <= 2 * n; j++) {
                                    if (nowf.a[j] == mx) nowf.a[j] = mi;
                                }
                                nowf.a[t - 1] = nowf.a[t] = 0;
                                montion(nowf);
                                hashx(nowf, nowr);
                            }
                        } else if ((bool)(bf.a[t - 1]) ^ (bool)(bf.a[t])) {
                            nowf = bf, nowr = br, nowr.fi++;
                            nowf.a[t - 1] = 0;
                            nowf.a[t] = bf.a[t - 1] + bf.a[t];
                            montion(nowf);
                            hashx(nowf, nowr);
                        } else {
                            nowf = bf, nowr = br;
                            hashx(nowf, nowr);
                        }
                    } else if (ap[i][t * 2 - 1] <= 6) {
                        if ((bool)(bf.a[t - 1]) ^ (bool)(bf.a[t])) {
                            if (bf.a[t - 1] + bf.a[t] <= 6) {
                                if ((bf.a[t - 1] + bf.a[t] + 1) / 2 == (ap[i][t * 2 - 1] + 1) / 2) {
                                    nowf = bf, nowr = br, nowr.fi++;
                                    nowf.a[t - 1] = nowf.a[t] = 0;
                                    hashx(nowf, nowr);
                                }
                            } else {
                                nowf = bf, nowr = br, nowr.fi++;
                                int mx = max(nowf.a[t - 1], nowf.a[t]);
                                for (int j = 0; j <= 2 * n; j++) {
                                    if (nowf.a[j] == mx) nowf.a[j] = ap[i][t * 2 - 1];
                                }
                                nowf.a[t - 1] = nowf.a[t] = 0;
                                montion(nowf);
                                hashx(nowf, nowr);
                            }
                        } else if (!bf.a[t - 1] && !bf.a[t]) {
                            nowf = bf, nowr = br, nowr.fi++;
                            nowf.a[t] = ap[i][t * 2 - 1];
                            nowf.a[t - 1] = 0;
                            hashx(nowf, nowr);
                        }
                    } else {
                        if (!bf.a[t - 1] && !bf.a[t]) {
                            nowf = bf, nowr = br;
                            hashx(nowf, nowr);
                        }
                    }
                }
                now ^= 1;
                for (int j = 1; j <= num[now]; j++) {
                    state[now][Hash[now][sta[now][j]]] = ro(0, 0);
                    sf[now][Hash[now][sta[now][j]]] = fin;
                    Hash[now][sta[now][j]] = 0;
                }
                num[now] = 0;
                for (int j = 1; j <= num[now ^ 1]; j++) {
                    bf = sf[now ^ 1][Hash[now ^ 1][sta[now ^ 1][j]]];
                    br = state[now ^ 1][Hash[now ^ 1][sta[now ^ 1][j]]];
                    if (!ap[i][t * 2]) {
                        if (bf.a[t]) {
                            nowf = bf, nowr = br, nowr.fi++;
                            nowf.a[t - 1] = bf.a[t];
                            nowf.a[t] = 0;
                            hashx(nowf, nowr);
                            nowf = bf, nowr = br, nowr.fi++;
                            nowf.a[t - 1] = 0;
                            nowf.a[t] = bf.a[t];
                            hashx(nowf, nowr);
                        } else {
                            nowf = bf, nowr = br, nowr.fi++;
                            nowf.a[t - 1] = nowf.a[t] = 13;
                            montion(nowf);
                            hashx(nowf, nowr);
                            nowf = bf, nowr = br;
                            hashx(nowf, nowr);
                        }
                    } else if (ap[i][t * 2] <= 6) {
                        if (bf.a[t] <= 6 && bf.a[t] != 0) {
                            if ((bf.a[t] + 1) / 2 == (ap[i][t * 2] + 1) / 2) {
                                nowf = bf, nowr = br, nowr.fi++;
                                nowf.a[t - 1] = nowf.a[t] = 0;
                                hashx(nowf, nowr);
                            }
                        } else if (!bf.a[t]) {
                            nowf = bf, nowr = br, nowr.fi++;
                            nowf.a[t - 1] = ap[i][t * 2];
                            hashx(nowf, nowr);
                            nowf = bf, nowr = br, nowr.fi++;
                            nowf.a[t] = ap[i][t * 2];
                            hashx(nowf, nowr);
                        } else {
                            nowf = bf, nowr = br, nowr.fi++;
                            for (int j = 0; j <= 2 * n; j++) {
                                if (nowf.a[j] == bf.a[t]) nowf.a[j] = ap[i][t * 2];
                            }
                            nowf.a[t] = 0;
                            montion(nowf);
                            hashx(nowf, nowr);
                        }
                    } else {
                        if (!bf.a[t]) {
                            nowf = bf, nowr = br;
                            hashx(nowf, nowr);
                        }
                    }
                }
            }
            now ^= 1;
            for (int j = 1; j <= num[now]; j++) {
                state[now][Hash[now][sta[now][j]]] = ro(0, 0);
                sf[now][Hash[now][sta[now][j]]] = fin;
                Hash[now][sta[now][j]] = 0;
            }
            num[now] = 0;
            for (int j = 1; j <= num[now ^ 1]; j++) {
                st nowf, bf;
                ro br;
                bf = sf[now ^ 1][Hash[now ^ 1][sta[now ^ 1][j]]];
                br = state[now ^ 1][Hash[now ^ 1][sta[now ^ 1][j]]];
                if (!bf.a[n * 2]) {
                    for (int t = 1; t <= n * 2; t++)
                        nowf.a[t] = bf.a[t - 1];
                    hashx(nowf, br);
                }
            }
        }
        int maxro = 999999999, maxid = 0;
        for (int i = 0; true; i = (i + 1) % mod) {
            if (!Hash[now][i]) {
                if (i == MOD - 1) break;
                i = (i + 1) % MOD;
                continue;
            }
            int flag1 = 0;
            for (int t = 0; t <= 2 * n; t++)
                if (sf[now][Hash[now][i]].a[t] != fin.a[t])
                    flag1 = 1;
            if (!flag1) {
                if (state[now][Hash[now][i]].fi - 3 < maxro) {
                    maxro = state[now][Hash[now][i]].fi - 3;
                    maxid = state[now][Hash[now][i]].sc;
                } else if (state[now][Hash[now][i]].fi - 3 == maxro) {
                    maxid = (maxid + state[now][Hash[now][i]].sc);
                }
            }
            if (i + 1 == MOD)
                break;
            i = (i + 1) % MOD;
        }
        maxid ? printf("%d %d
", maxro, maxid) : printf("-1 -1
");;
    }
    return 0;
}