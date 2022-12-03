#include <iostream>

using namespace std;

int f[2005][2005];
string a, b;

inline int dfs(int i, int j) {
    if (f[i][j])
        return f[i][j];
    if (!i)
        return f[0][j] = j;
    if (!j)
        return *f[i] = i;
    return f[i][j] = min(min(dfs(i - 1, j) + 1, dfs(i, j - 1) + 1), dfs(i - 1, j - 1) + (a[i - 1] != b[j - 1]));
}

int main() {
    cin >> a >> b;
    cout << dfs(a.size(), b.size());
    return 0;
}