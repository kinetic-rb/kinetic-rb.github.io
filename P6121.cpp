#include <iostream>
#include <vector>

using namespace std;

int b[200005], s[200005], ask[200005], pushed[200005];
vector<int> e[200005];
string ans[200005];

inline void init(int n) {
    for (int i = 0; i < n; i++)
        s[b[i] = i] = 1;
}

inline int find(int u) {
    return (b[u] == u ? u : b[u] = find(b[u]));
}

inline void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (s[u] < s[v])
        swap(u, v);
    b[u] = v;
    s[v] += s[u];
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = n - 1; i > -1; i--) {
        cin >> ask[i];
    }
    for (int i = 0; i < n; i++) {
        pushed[ask[i]] = true;
        for (auto j : e[ask[i]]) {
            if (pushed[j]) {
                merge(j, ask[i]);
            }
        }
        ans[n - i - 1] = (s[find(ask[i])] == i + 1 ? "YES
" : "NO
");
    }
    for (auto i : ans)
        cout << i;
    return 0;
}