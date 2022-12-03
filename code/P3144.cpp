#include <iostream>
#include <cstring>

using namespace std;

struct AC {
    int v, next;
} e[30003];

bool vis[30003], ok[30003]; //ok[i]\u4e3aFALSE i\u53ef\u7528
int head[30003], u[30003], v[30003];
int vnt, tot;

inline void dfs(int u) {
    if (vis[u])
        return;
    vnt++;
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
        dfs(e[i].v);
    }
}

inline void ADD(int u, int v) {
    e[++tot].v = v;
    e[tot].next = head[u];
    head[u] = tot;
}

int main() {
    int n, m, f;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
    }
    for (int i = 0; i < n; i++) {
        memset(vis, false, sizeof vis);
        memset(head, 0, sizeof head);
        tot = 0;
        int x;
        cin >> x;
        for (int j = 0; j < m; j++)
            if (!ok[u[j]] && !ok[v[j]]) {
                ADD(u[j], v[j]);
                ADD(v[j], u[j]);
                f = u[j];
            }
        vnt = 0;
        dfs(f);
        cout << (vnt == n - i ? "YES
" : "NO
");
        ok[x] = true;
    }
    return 0;
}