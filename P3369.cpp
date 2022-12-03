#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

template<unsigned SIZET>
class RBTree {
    enum { B, R };

    int ch[SIZET][2], * sz = new int[SIZET], * cnt = new int[SIZET], * p = new int[SIZET], * keys = new int[SIZET];
    vector<bool> color;

    int root, tree_size;

public:

    RBTree() {
        color.resize(SIZET);
        root = tree_size = 0;
    }

    inline void rotate(int x, bool right) {
        int y = ch[x][!right];
        ch[x][!right] = ch[y][right];
        if (ch[y][right])
            p[ch[y][right]] = x;
        p[y] = p[x];
        ch[(not p[x] ? root : ch[p[x]][x == ch[p[x]][1]]) = y][right] = x;
        p[x] = y;
        sz[y] = sz[x];
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
    }

    inline void transplant(int to, int from) {
        p[from] = p[to];
        (not p[to] ? root : ch[p[to]][to == ch[p[to]][1]]) = from;
    }

    inline int findMin(int x) {
        while (ch[x][0])
            x = ch[x][0];
        return x;
    }

    inline int findMax(int x) {
        while (ch[x][1])
            x = ch[x][1];
        return x;
    }

    inline int findNode(int k) {
        for (int x = root; x; x = ch[x][keys[x] < k])
            if (keys[x] == k)
                return x;
        return 0x7fffffff;
    }

    inline int find(int k) {
        int x;
        if ((x = findNode(k)) != 0x7fffffff)
            return keys[x];
        return 0x7fffffff;
    }

    inline void putFixUp(int z) {
        while (color[p[z]] == R) {
            int fa = p[z], grand = p[fa];
            bool is_left = fa == ch[grand][0];
            int y = ch[grand][is_left];
            if (color[y] == R) {
                color[y] = color[fa] = B;
                color[grand] = R;
                z = grand;
            }
            else {
                if (z == ch[fa][is_left])
                    rotate(z = fa, !is_left);
                color[p[z]] = B;
                color[p[p[z]]] = R;
                rotate(grand, is_left);
            }
        }
        color[root] = B;
    }

    inline void put(int k) {
        int y = 0;
        for (int x = root; x; x = ch[x][keys[x] < k]) {
            ++sz[y = x];
            if (keys[x] == k) {
                ++cnt[x];
                return;
            }
        }
        keys[++tree_size] = k;
        color[tree_size] = R;
        p[tree_size] = y;
        sz[tree_size] = cnt[tree_size] = 1;
        putFixUp((not y ? root : ch[y][keys[y] < k]) = tree_size);
    }

    inline void delFixUp(int x) {
        while (x != root && color[x] == B) {
            bool is_left = x == ch[p[x]][0];
            int fa = p[x], w = ch[fa][is_left];
            if (color[w] == R) {
                color[fa] = R;
                color[w] = B;
                rotate(fa, !is_left);
                w = ch[fa][is_left];
            }
            if (color[ch[w][0]] == B && color[ch[w][1]] == B) {
                color[w] = R;
                x = p[x];
            }
            else {
                if (color[ch[w][is_left] == B]) {
                    color[w] = R;
                    color[ch[w][!is_left]] = B;
                    rotate(w, is_left);
                    w = ch[fa][is_left];
                }
                color[w] = color[fa];
                color[fa] = B;
                color[ch[w][is_left]] = B;
                rotate(p[w], !is_left);
                x = root;
            }
        }
        color[x] = B;
    }

    inline void del(int k) {
        int z = root, w = 0;
        while (z) {
            sz[w = z]--;
            if (k == keys[z])
                break;
            z = ch[z][keys[z] < k];
        }
        if (z) {
            if (cnt[z] > 1) {
                --cnt[z];
                return;
            }
            int y = z, x;
            bool oldColor = color[y];
            if (not ch[z][0]) {
                x = ch[z][1];
                transplant(z, ch[z][1]);
            }
            else if (not ch[z][1]) {
                x = ch[z][0];
                transplant(z, ch[z][0]);
            }
            else {
                y = findMin(ch[z][1]);
                oldColor = color[y];
                x = ch[y][1];
                if (p[y] == z)
                    p[x] = y;
                else {
                    int tempy = y;
                    while (tempy != z) {
                        sz[tempy] -= cnt[y];
                        tempy = p[tempy];
                    }
                    transplant(y, ch[y][1]);
                    ch[y][1] = ch[z][1];
                    p[ch[y][1]] = y;
                }
                transplant(z, y);
                ch[y][0] = ch[z][0];
                p[ch[y][0]] = y;
                color[y] = color[z];
                sz[y] = sz[ch[y][0]] + sz[ch[y][1]] + cnt[y];
            }
            if (oldColor == B)
                delFixUp(x);
        }
        else
            while (w) {
                ++sz[w];
                w = p[w];
            }
    }

    inline void inorderWalk(int x, void pred(int k, int cnt)) {
        if (ch[x][0])
            inorderWalk(ch[x][0], pred);
        pred(keys[x], cnt[x]);
        if (ch[x][1])
            inorderWalk(ch[x][1], pred);
    }

    inline int countLower(int rend, bool canEqual) {
        int ret = 0;
        for (int x = root; x;) {
            if (keys[x] < rend || (canEqual && !(rend < keys[x]) && !(keys[x] < rend))) {
                ret += sz[ch[x][0]] + cnt[x];
                x = ch[x][1];
            }
            else
                x = ch[x][0];
        }
        return ret;
    }

    inline int countBetween(int lend, int rend) {
        return countLower(rend, true) - countLower(lend, false);
    }

    inline int findNext(int k) {
        put(k);
        int ret, x = findNode(k);
        if (ch[x][1])
            ret = keys[findMin(ch[x][1])];
        else {
            while (ch[p[x]][1] == x)
                x = p[x];
            ret = (not p[x]) ? 0x7fffffff : keys[p[x]];
        }
        del(k);
        return ret;
    }

    inline int findPrev(int k) {
        put(k);
        int ret, x = findNode(k);
        if (ch[x][0])
            ret = keys[findMax(ch[x][0])];
        else {
            while (ch[p[x]][0] == x)
                x = p[x];
            ret = (not p[x] ? 0x7fffffff : keys[p[x]]);
        }
        del(k);
        return ret;
    }

    inline int findKthSmallest(int k) {
        for (int x = root; x;) {
            int l = ch[x][0], r = ch[x][1];
            if (sz[l] + 1 <= k && sz[l] + cnt[x] >= k)
                return keys[x];
            else
                if (sz[l] + cnt[x] < k) {
                    k -= sz[l] + cnt[x];
                    x = r;
                }
                else
                    x = l;
        }
        return 0x7fffffff;
    }

    ~RBTree() {

    }
};

int main() {
    RBTree<100001> rb;
    int n;
    cin >> n;
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        switch (opt) {
        case 1:
            rb.put(x);
            break;
        case 2:
            rb.del(x);
            break;
        case 3:
            printf("%d
", rb.countLower(x, false) + 1);
            break;
        case 4:
            printf("%d
", rb.findKthSmallest(x));
            break;
        case 5:
            printf("%d
", rb.findPrev(x));
            break;
        case 6:
            printf("%d
", rb.findNext(x));
            break;
        }
    }
    return 0;
}