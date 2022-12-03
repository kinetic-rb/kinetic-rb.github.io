#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> f(361);
    vector<int> deg;
    *f.begin() = true;
    int n, m;
    cin >> n >> m;
    deg.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> deg[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = deg[i]; j < 1000; j++) {
            f[j % 360] = max(f[j % 360], f[(j - deg[i]) % 360]);
            f[j % 360] = max(f[j % 360], f[(j + deg[i]) % 360]);
        }
    }
    for (int x; cin >> x; cout << (f[x] ? "YES
" : "NO
"));
    return 0;
}