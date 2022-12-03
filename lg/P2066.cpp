#include <iostream>

using namespace std;

int num[20][20], cho[20];
int n, m, MAX;

inline void dfs(int idx = 0, int sum = 0) {
    if (idx == n) {
        if (sum == m) {
            int tot = 0;
            for (int i = 0; i < n; i++)
                tot += num[i][cho[i]];
            MAX = max(MAX, tot);
        }
        return;
    }
    for (int i = 0; i <= m; i++) {
        if (sum + i > m)
            return;
        cho[idx] = i;
        dfs(idx + 1, sum + i);
    }
}

inline void findans(int idx = 0, int sum = 0) {
    if (idx == n) {
        if (sum == m) {
            int tot = 0;
            for (int i = 0; i < n; i++)
                tot += num[i][cho[i]];
            if (tot == MAX) {
                for (int i = 0; i < n; i++)
                    cout << i + 1 << ' ' << cho[i] << '\n';
                exit(0);
            }
        }
        return;
    }
    for (int i = 0; i <= m; i++) {
        if (sum + i > m)
            return;
        cho[idx] = i;
        findans(idx + 1, sum + i);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= m; j++)
            cin >> num[i][j];
    dfs();
    cout << MAX << '\n';
    findans();
    return 0;
}