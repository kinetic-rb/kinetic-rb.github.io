#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct node {
\tint l, r;
\tmutable int val;
\tinline bool operator < (const node& comp) const {
\t\treturn l < comp.l;
\t}
};

set<node> s;

inline void out() {
\tfor (node i : s)
\t\tfor (int j = i.l; j <= i.r; j++)
\t\t\tprintf("%d ", i.val);
\tputchar('\n');
}

inline void insert(int l, int r = 0, int v = 0) {
\ts.insert({ l, r, v });
}

inline set<node>::iterator split(int pos) {
\tset<node>::iterator it = s.lower_bound({ pos });
\tif (it != s.end() && it->l == pos)
\t\treturn it;
\tconst int l = (--it)->l, r = it->r, v = it->val;
\ts.erase(it);
\ts.insert({ l, pos - 1, v });
\treturn s.insert({ pos, r, v }).first;
}

inline int sum(int l, int r) {
\tint ret = 0;
\tfor (set<node>::iterator R = split(r + 1), L = split(l); L != R; L++)
\t\tret = (ret + (L->r - L->l + 1LL) * L->val) % 1000000007;
\treturn ret;
}

inline void assign(int l, int r, int val) {
\tset<node>::iterator R = split(r + 1), L = split(l);
\ts.erase(L, R);
\ts.insert({ l, r, val });
}

inline void add(int l, int r, int v) {
\tfor (set<node>::iterator R = split(r + 1), L = split(l); L != R; L++) {
\t\tL->val += v;
\t\tL->val += L->val >> 31 & 1000000007;
\t}
}

inline void clone(int l1, int r1, int l2, int r2) {
\tstatic vector<node> vec;
\tvec.clear();
\tfor (set<node>::iterator R = split(r1 + 1), L = split(l1); L != R; L++)
\t\tvec.push_back(*L);
\tset<node>::iterator R = split(r2 + 1), L = split(l2);
\ts.erase(L, R);
\tfor (node i : vec)
\t\ts.insert({ i.l - l1 + l2, i.r - l1 + l2, i.val });
}

inline void swap(int l1, int r1, int l2, int r2) {
\tif (l1 > l2) {
\t\tl1 ^= l2 ^= l1 ^= l2;
\t\tr1 ^= r2 ^= r1 ^= r2;
\t}
\tstatic vector<node> v1, v2;
\tv1.clear();
\tv2.clear();
\tfor (set<node>::iterator R = split(r1 + 1), L = split(l1); L != R; ++L)
\t\tv1.push_back(*L);
\tfor (set<node>::iterator R = split(r2 + 1), L = split(l2); L != R; ++L)
\t\tv2.push_back(*L);
\tset<node>::iterator R = split(r1 + 1), L = split(l1);
\ts.erase(L, R);
\tR = split(r2 + 1);
\tL = split(l2);
\ts.erase(L, R);
\tfor (node i : v1)
\t\tinsert(i.l - l1 + l2, i.r - l1 + l2, i.val);
\tfor (node i : v2)
\t\tinsert(i.l - l2 + l1, i.r - l2 + l1, i.val);
}

inline void reverse(int l, int r) {
\tstatic vector<node> vec;
\tvec.clear();
\tfor (set<node>::iterator R = split(r + 1), L = split(l); L != R; L++)
\t\tvec.push_back(*L);
\tset<node>::iterator R = split(r + 1), L = split(l);
\ts.erase(L, R);
\tfor (node i : vec)
\t\ts.insert({ r - i.r + l, r - i.l + l, i.val });
}

int main() {
    ios_base::sync_with_stdio(false);
\tint n, m;
\tcin >> n >> m;
\tfor (int i = 1; i <= n; i++) {
\t\tint t;
\t\tcin >> t;
\t\tinsert(i, i, t);
\t}
\tinsert(n + 1);
\twhile (m--) {
\t\tint op;
\t\tcin >> op;
\t\tswitch (op) {
\t\t\tcase 1: {
\t\t\t\tint l, r;
\t\t\t\tcin >> l >> r;
\t\t\t\tprintf("%d
", sum(l, r));
\t\t\t\tbreak;
\t\t\t}
\t\t\tcase 2: {
\t\t\t\tint l, r, v;
\t\t\t\tcin >> l >> r >> v;
\t\t\t\tassign(l, r, v);
\t\t\t\tbreak;
\t\t\t}
\t\t\tcase 3: {
\t\t\t\tint l, r, v;
\t\t\t\tcin >> l >> r >> v;
\t\t\t\tadd(l, r, v - 1000000007);
\t\t\t\tbreak;
\t\t\t}
\t\t\tcase 4: {
\t\t\t\tint l1, r1, l2, r2;
\t\t\t\tcin >> l1 >> r1 >> l2 >> r2;
\t\t\t\tclone(l1, r1, l2, r2);
\t\t\t\tbreak;
\t\t\t}
\t\t\tcase 5: {
\t\t\t\tint l1, r1, l2, r2;
\t\t\t\tcin >> l1 >> r1 >> l2 >> r2;
\t\t\t\tswap(l1, r1, l2, r2);
\t\t\t\tbreak;
\t\t\t}
\t\t\tcase 6: {
\t\t\t\tint l, r;
\t\t\t\tcin >> l >> r;
\t\t\t\treverse(l, r);
\t\t\t\tbreak;
\t\t\t}
\t\t}
\t}
\tout();
\treturn 0;
}