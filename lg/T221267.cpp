#include <iostream>

using namespace std;

int ac[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        static int last = 0;
        int x;
        cin >> x;
        ac[i] = x - last;
        last = x;
    }
    for(int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        ac[l] += c;
        ac[r + 1] -= c;
    }
    for(int i = 1; i <= n; i++) {
        ac[i] += ac[i - 1];
        cout << ac[i] << ' ';
    }
    return 0;
}