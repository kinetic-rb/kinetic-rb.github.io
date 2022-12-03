#include <iostream>
#include <algorithm>
#include "cmath"
#include "cstdio"

using namespace std;

#pragma ScapegoatTree
#include <vector>

using std :: vector;

struct Scapegoat {
    Scapegoat *left, *right;
    int key, size, cnt;
    bool deleted;
    bool needrebuild() const {
        return left->cnt > 0.7 * cnt + 5 || right->cnt > 0.7 * cnt + 5;
    }
    void maintain() {
        size = !deleted + left->size + right->size;
        cnt = 1 + left->cnt + right->cnt;
    }
}*null, *root;

inline void helprebuild(Scapegoat *o, vector <Scapegoat*> &v) {
    if (o == null)
        return;
    helprebuild(o->left, v);
    if (!o->deleted)
        v.push_back(o);
    helprebuild(o->right, v);
    if (o->deleted)
        delete o;
}

inline Scapegoat *build(vector <Scapegoat*> &v, int l, int r) {
    if (l >= r)
        return null;
    auto mid = (l + r) >> 1;
    Scapegoat *o = v[mid];
    o->left = build(v, l, mid);
    o->right = build(v, mid + 1, r);
    o->maintain();
    return o;
}

inline void rebuild(Scapegoat* &o) {
    vector <Scapegoat *> v;
    helprebuild(o, v);
    o = build(v, 0, v.size());
}

inline void insert(int x, Scapegoat* &o) {
    if (o == null) {
        o = new Scapegoat;
        o->left = o->right = null;
        o->deleted = false;
        o->size = o->cnt = 1;
        o->key = x;
        return;
    } else {
        ++o->size;
        ++o->cnt;
        (x >= o->key) ? insert(x, o->right) : insert(x, o->left);
        if (o->needrebuild()) {
            rebuild(o);
        }
    }
}

inline int rank(Scapegoat *now, int x) {
    auto ans = 1;
    while (now != null) {
        if (now->key >= x) {
            now = now->left;
        } else {
            ans += now->left->size + !now->deleted;
            now = now->right;
        }
    }
    return ans;
}

inline int numberth(Scapegoat *now, int x) {
    while (now != null) {
        if (!now->deleted && now->left->size + 1 == x)
            return now->key;
        if (now->left->size >= x) {
            now = now->left;
        } else {
            x -= now->left->size + !now->deleted;
            now = now->right;
        }
    }
}

inline void del(Scapegoat *o, int rank) {
    if (!o->deleted && rank == o->left->size + 1) {
        o->deleted = true;
        --o->size;
        return;
    }
    --o->size;
    (rank <= o->left->size + !o->deleted) ? del(o->left, rank) : del(o->right, rank - o->left->size - !o->deleted);
}

int LIVE[100001];

int main() {
    root = null = new Scapegoat;
    ios_base ::sync_with_stdio(false);
    register int n, w;
    register bool x = true;
    scanf("%d%d", &n, &w);
    insert(0, root);
    for(register int i = 1; i <= n; i++) {
        scanf("%d", &LIVE[i]);
        insert(LIVE[i], root);
        register int nt = max(1, 1 + i - int(floor(i * w * 1.0 / 100)));
        if(i != 1 && LIVE[i] != LIVE[i - 1] && x) {
            del(root, 1);
            x = false;
        }
        printf("%d ", numberth(root, nt) > 800 ? numberth(root, --nt) : numberth(root, nt));
        //cout << int(floor(i * w * 1.0 / 100)) << endl;
    }
    return 0;
}